"""
Configuration file for Job Scraper Bot
Centralized settings for all phases
"""
import os
from dotenv import load_dotenv

load_dotenv()

# ============ TELEGRAM CONFIG ============
TELEGRAM_BOT_TOKEN = os.getenv("TELEGRAM_BOT_TOKEN", "YOUR_BOT_TOKEN_HERE")
TELEGRAM_CHAT_ID = os.getenv("TELEGRAM_CHAT_ID", "YOUR_CHAT_ID_HERE")

# ============ SCRAPER CONFIG ============
SCRAPER_SOURCES = {
    "bdjobs": {
        "enabled": True,
        "url": "https://www.bdjobs.com/jobsearch.asp",
        "type": "static"  # static = requests+BS4, dynamic = selenium
    },
    "linkedin": {
        "enabled": True,
        "url": "https://www.linkedin.com/jobs",
        "type": "dynamic"
    },
    "facebook": {
        "enabled": False,  # requires login
        "url": "https://www.facebook.com/groups",
        "type": "dynamic"
    }
}

# ============ FILTER CONFIG ============
KEYWORDS_INCLUDE = [
    "intern", "internship", "trainee",
    "developer", "engineer", "programmer",
    "python", "django", "fastapi", "html", "css"
]

KEYWORDS_EXCLUDE = [
    "senior", "experienced", "10+ years",
    "contract - to - hire"
]

# ============ DATABASE CONFIG ============
DATABASE_TYPE = "sqlite"  # Options: sqlite, postgresql
DB_PATH = "data/jobs.db"
DB_HOST = os.getenv("DB_HOST", "localhost")
DB_USER = os.getenv("DB_USER", "root")
DB_PASSWORD = os.getenv("DB_PASSWORD", "")
DB_NAME = os.getenv("DB_NAME", "job_scraper")

# ============ LOGGING CONFIG ============
LOG_LEVEL = "INFO"
LOG_FILE = "logs/bot.log"

# ============ SCRAPER BEHAVIOR ============
REQUEST_TIMEOUT = 10
RETRY_ATTEMPTS = 3
USER_AGENT = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36"

# ============ SCHEDULER CONFIG ============
SCRAPE_INTERVAL_HOURS = 2  # Run scraper every 2 hours
