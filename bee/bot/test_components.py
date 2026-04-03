"""
Quick Start Guide - Run this first!
Tests individual components WITHOUT needing real credentials
"""
import logging
from pathlib import Path

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

print("\n" + "="*60)
print("🤖 JOB SCRAPER BOT - COMPONENT TEST")
print("="*60)

# Test 1: Check dependencies
print("\n1️⃣  CHECKING DEPENDENCIES...")
try:
    import requests
    print("   ✓ requests installed")
    import bs4
    print("   ✓ beautifulsoup4 installed")
    import telegram
    print("   ✓ python-telegram-bot installed")
    print("   ✅ All dependencies OK!")
except ImportError as e:
    print(f"   ❌ Missing: {e}")
    print("   Run: pip install -r requirements.txt")

# Test 2: Check file structure
print("\n2️⃣  CHECKING PROJECT STRUCTURE...")
required_dirs = [
    'scrapers', 'processors', 'database', 'notifier', 'logs', 'data'
]
required_files = [
    'bot.py', 'config.py', 'requirements.txt', '.env.template'
]

for dir_name in required_dirs:
    path = Path(dir_name)
    if path.exists():
        print(f"   ✓ /{dir_name}/")
    else:
        print(f"   ❌ /{dir_name}/ missing")

for file_name in required_files:
    if Path(file_name).exists():
        print(f"   ✓ {file_name}")
    else:
        print(f"   ❌ {file_name} missing")

# Test 3: Test each component
print("\n3️⃣  TESTING COMPONENTS...")

try:
    from database.db_manager import DBManager
    db = DBManager()
    stats = db.get_stats()
    print(f"   ✓ Database: {stats}")
except Exception as e:
    print(f"   ❌ Database error: {e}")

try:
    from processors.job_processor import JobProcessor
    processor = JobProcessor()
    print(f"   ✓ Processor loaded with {len(processor.keywords_include)} keywords")
except Exception as e:
    print(f"   ❌ Processor error: {e}")

try:
    from scrapers.bdjobs_scraper import BDJobsScraper
    print(f"   ✓ BD Jobs Scraper ready")
except Exception as e:
    print(f"   ❌ Scraper error: {e}")

# Test 4: Test processing pipeline
print("\n4️⃣  TESTING PIPELINE (with dummy data)...")
try:
    test_jobs = [
        {
            'title': 'Python Developer Internship - Django Expert',
            'company': 'Tech Startup',
            'link': 'http://test.com/job1',
            'description': 'Looking for Django and FastAPI developer',
            'source': 'test'
        },
        {
            'title': 'Senior Java Engineer - 10+ Years',
            'company': 'Old Corp',
            'link': 'http://test.com/job2',
            'description': 'Need experienced Java developer',
            'source': 'test'
        }
    ]
    
    filtered, total = processor.process_jobs(test_jobs)
    print(f"   Input: {total} jobs")
    print(f"   ✓ Filtered: {len(filtered)} relevant jobs")
    
    if filtered:
        job = filtered[0]
        print(f"   Sample: {job['title']}")
        print(f"   Tags: {job['tags']}")
        
        # Try DB operations
        added = db.add_job(job)
        print(f"   ✓ DB: Job {'added' if added else 'exists'}")
    
except Exception as e:
    print(f"   ❌ Pipeline error: {e}")

# Test 5: Configuration
print("\n5️⃣  CHECKING CONFIGURATION...")
try:
    from config import TELEGRAM_BOT_TOKEN, TELEGRAM_CHAT_ID
    
    if TELEGRAM_BOT_TOKEN == "YOUR_BOT_TOKEN_HERE":
        print("   ⚠️  TELEGRAM_BOT_TOKEN not configured")
        print("   → Create .env file from .env.template")
        print("   → Add your token from @BotFather")
    else:
        print("   ✓ Telegram token configured")
    
    if TELEGRAM_CHAT_ID == "YOUR_CHAT_ID_HERE":
        print("   ⚠️  TELEGRAM_CHAT_ID not configured")
    else:
        print("   ✓ Telegram chat ID configured")
        
except Exception as e:
    print(f"   ❌ Config error: {e}")

print("\n" + "="*60)
print("✅ COMPONENT TEST COMPLETE!")
print("="*60)
print("\n📖 NEXT STEPS:")
print("   1. Create .env file from .env.template")
print("   2. Add your Telegram bot credentials")
print("   3. Run: python bot.py")
print("   4. Or schedule: Edit bot.py -> uncomment schedule_pipeline()")
print("\n🚀 Ready to go! Let's start scraping!\n")
