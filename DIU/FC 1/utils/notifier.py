import requests
import time
from html import escape
from config import TELEGRAM_BOT_TOKEN, TELEGRAM_CHAT_ID

def generate_tags(title, keywords):
    """Auto-generates hashtags based on title matches."""
    tags = []
    title_lower = title.lower()
    for kw in keywords:
        if kw.lower() in title_lower:
            tags.append(f"#{kw.replace(' ', '')}")
    
    # Fallback tag
    if not tags:
        tags.append("#FreeCourse")
        
    return " ".join(tags[:5]) # Limit to 5 tags

def format_message(course, keywords):
    title = escape(course['title'])
    link = escape(course['link'])
    tags = escape(generate_tags(course['title'], keywords))
    
    # Template Selection
    if course['platform'] == 'Udemy':
        header = "Udemy FREE Course (Coupon)"
        note = "Limited time coupon. 100% Free."
    elif course['platform'] == 'Coursera':
        header = "Coursera (Free Audit)"
        note = "Course content is free. Certificate requires payment."
    elif course['platform'] == 'freeCodeCamp':
        header = "freeCodeCamp (Always Free)"
        note = "Includes free certificate."
    else:
        header = f"{course['platform']} (Free)"
        note = "Check platform details."

    msg = (
        f"<b>{escape(header)}</b>\n\n"
        f"<b>Title:</b> {title}\n"
        f"<b>Tags:</b> {tags}\n"
        f"<b>Note:</b> {escape(note)}\n\n"
        f"<a href=\"{link}\">Link to Course</a>"
    )
    return msg

def send_telegram_alert(course, keywords):
    message = format_message(course, keywords)
    url = f"https://api.telegram.org/bot{TELEGRAM_BOT_TOKEN}/sendMessage"
    payload = {
        "chat_id": TELEGRAM_CHAT_ID,
        "text": message,
        "parse_mode": "HTML",
        "disable_web_page_preview": False
    }
    
    try:
        response = requests.post(url, json=payload, timeout=10)
        response.raise_for_status()
        time.sleep(1) # Rate limit protection for Telegram
        return True
    except Exception as e:
        print(f"Error sending to Telegram: {e}")
        return False