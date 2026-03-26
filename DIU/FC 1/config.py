import os

try:
    from dotenv import load_dotenv
    load_dotenv()
except Exception:
    pass

# Secrets (Load from Environment Variables for Security)
TELEGRAM_BOT_TOKEN = (
    os.getenv("TELEGRAM_BOT_TOKEN")
    or os.getenv("BOT_TOKEN")
    or "YOUR_TOKEN_HERE"
)
TELEGRAM_CHAT_ID = (
    os.getenv("TELEGRAM_CHAT_ID")
    or os.getenv("CHAT_ID")
    or "YOUR_CHANNEL_ID"
)

# Database File
DB_FILE = "courses.db"

# High-Value Keywords (Case Insensitive)
KEYWORDS = [
    "Python", "Java", "Machine Learning", "Data Science", "AI",
    "React", "Node", "AWS", "Cloud", "Cybersecurity", "Linux",
    "Docker", "Kubernetes", "Ethical Hacking"
]

# User-Agent to avoid being blocked
HEADERS = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36"
}