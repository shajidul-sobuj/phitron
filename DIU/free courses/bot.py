import os

try:
    from dotenv import load_dotenv
except ImportError:
    load_dotenv = None

import requests
from bs4 import BeautifulSoup

# ========= ENV =========
if load_dotenv:
    load_dotenv()
BOT_TOKEN = os.getenv("BOT_TOKEN")
CHAT_ID = os.getenv("CHAT_ID")

if not BOT_TOKEN or not CHAT_ID:
    raise RuntimeError("Missing BOT_TOKEN or CHAT_ID environment variables")

HEADERS = {"User-Agent": "Mozilla/5.0"}
MAX_PER_SOURCE = 5

# ========= SOURCES =========
COURSERA_SEARCH = "https://www.coursera.org/search?query="
DISCUDEMY_URL = "https://www.discudemy.com/all"
EDX_URL = "https://www.edx.org/search?tab=course&price=free"
FREECODECAMP_URL = "https://www.freecodecamp.org/learn/"

# ========= KEYWORDS (PUBLIC SAFE) =========
KEYWORDS = [
    "python", "ai", "machine learning", "data",
    "web", "react", "cloud", "aws",
    "cyber", "security", "linux"
]

# ========= HELPERS =========
def matches_keywords(title):
    t = title.lower()
    return any(k in t for k in KEYWORDS)

def extract_tags(title):
    t = title.lower()
    return [k for k in KEYWORDS if k in t][:5]

def format_tags(tags):
    return " ".join(f"#{t.replace(' ', '')}" for t in tags)

def send_telegram(text):
    url = f"https://api.telegram.org/bot{BOT_TOKEN}/sendMessage"
    data = {
        "chat_id": CHAT_ID,
        "text": text,
        "disable_web_page_preview": False
    }
    requests.post(url, data=data, timeout=15)

def build_message(source, title, link, note=None):
    tags = format_tags(extract_tags(title))
    lines = [
        source,
        f"Title: {title}",
    ]
    if tags:
        lines.append(f"Tags: {tags}")
    if note:
        lines.append(f"Note: {note}")
    lines.append(f"Link: {link}")
    return "\n".join(lines)

# ========= COURSERA (AUDIT FREE ONLY) =========
def check_coursera():
    res = requests.get(COURSERA_SEARCH + "free", headers=HEADERS, timeout=20)
    soup = BeautifulSoup(res.text, "html.parser")

    sent, seen = 0, set()

    for h3 in soup.find_all("h3"):
        title = h3.get_text(strip=True)
        if not title or title in seen:
            continue
        seen.add(title)

        if not matches_keywords(title):
            continue

        link = COURSERA_SEARCH + title.replace(" ", "%20")
        msg = build_message(
            "🎓 Coursera (Free Audit)",
            title,
            link,
            note="Course content free. Certificate may be paid."
        )
        send_telegram(msg)
        sent += 1
        if sent >= MAX_PER_SOURCE:
            break

# ========= DISCUDEMY (100% FREE COUPON) =========
def check_discudemy():
    res = requests.get(DISCUDEMY_URL, headers=HEADERS, timeout=20)
    soup = BeautifulSoup(res.text, "html.parser")

    sent = 0

    for a in soup.find_all("a", class_="card-header"):
        title = a.get_text(strip=True)
        if not title or not matches_keywords(title):
            continue

        link = "https://www.discudemy.com" + a["href"]
        msg = build_message(
            "🔥 Udemy FREE (Coupon)",
            title,
            link
        )
        send_telegram(msg)
        sent += 1
        if sent >= MAX_PER_SOURCE:
            break

# ========= EDX (FREE CONTENT) =========
def check_edx():
    res = requests.get(EDX_URL, headers=HEADERS, timeout=20)
    soup = BeautifulSoup(res.text, "html.parser")

    sent, seen = 0, set()

    for a in soup.select("a[href*='/course/']"):
        title = a.get_text(" ", strip=True)
        if not title or title in seen:
            continue
        seen.add(title)

        if not matches_keywords(title):
            continue

        link = "https://www.edx.org" + a["href"].split("?")[0]
        msg = build_message(
            "🎓 edX (Free Content)",
            title,
            link,
            note="Course free. Certificate may be paid."
        )
        send_telegram(msg)
        sent += 1
        if sent >= MAX_PER_SOURCE:
            break

# ========= FREECODECAMP (100% FREE + CERTIFICATE) =========
def check_freecodecamp():
    res = requests.get(FREECODECAMP_URL, headers=HEADERS, timeout=20)
    soup = BeautifulSoup(res.text, "html.parser")

    sent, seen = 0, set()

    for h in soup.select("h2, h3"):
        title = h.get_text(" ", strip=True)
        if not title or title in seen:
            continue
        seen.add(title)

        if not matches_keywords(title):
            continue

        slug = title.lower().replace(" ", "-")
        link = FREECODECAMP_URL + slug

        msg = build_message(
            "🎓 freeCodeCamp (100% Free + Certificate)",
            title,
            link
        )
        send_telegram(msg)
        sent += 1
        if sent >= MAX_PER_SOURCE:
            break

# ========= RUN =========
def main():
    check_discudemy()     # 100% free first
    check_freecodecamp()  # always free
    check_coursera()      # audit free
    check_edx()           # free content

if __name__ == "__main__":
    main()
