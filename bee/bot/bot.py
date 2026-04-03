"""
Main Bot Orchestrator
Coordinates all components: Scraper → Processor → DB → Notifier
This is the main entry point for the application
"""
import logging
import io
import sys
import schedule
import time
from datetime import datetime
from typing import List, Dict

from config import (
    TELEGRAM_BOT_TOKEN, TELEGRAM_CHAT_ID, 
    SCRAPER_SOURCES, DB_PATH, LOG_LEVEL, LOG_FILE,
    SCRAPE_INTERVAL_HOURS
)
from database.db_manager import DBManager
from scrapers.test_scraper import TestScraper
from scrapers.bdjobs_scraper import BDJobsScraper
from processors.job_processor import JobProcessor
from notifier.telegram_notifier import TelegramNotifier

# ============ LOGGING SETUP ============
import io
import sys

# Fix Unicode encoding on Windows
if sys.platform == 'win32':
    # Reconfigure stdout to use UTF-8
    sys.stdout = io.TextIOWrapper(sys.stdout.buffer, encoding='utf-8')

logging.basicConfig(
    level=getattr(logging, LOG_LEVEL),
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    handlers=[
        logging.FileHandler(LOG_FILE, encoding='utf-8'),
        logging.StreamHandler(sys.stdout)
    ]
)
logger = logging.getLogger(__name__)


class JobScraperBot:
    """Main bot that orchestrates the entire pipeline"""
    
    def __init__(self):
        logger.info("🤖 Initializing Job Scraper Bot...")
        
        self.db = DBManager(DB_PATH)
        self.processor = JobProcessor()
        self.notifier = TelegramNotifier(TELEGRAM_BOT_TOKEN, TELEGRAM_CHAT_ID)
        self.scrapers = self._init_scrapers()
        
        logger.info("✅ Bot initialized successfully!")
    
    def _init_scrapers(self):
        """Initialize all enabled scrapers"""
        scrapers = {}
        
        # Use test scraper for demonstration
        scrapers['test'] = TestScraper()
        logger.info("✓ Test scraper initialized")
        
        # Uncomment below to use actual BD Jobs scraper
        # if SCRAPER_SOURCES['bdjobs']['enabled']:
        #     scrapers['bdjobs'] = BDJobsScraper()
        #     logger.info("✓ BD Jobs scraper initialized")
        
        # TODO: Add LinkedIn scraper
        # TODO: Add Facebook scraper
        
        return scrapers
    
    def run_pipeline(self) -> Dict:
        """
        Run complete pipeline:
        Scrape → Process → Deduplicate → Send → Save
        Returns statistics
        """
        logger.info("=" * 50)
        logger.info("🚀 Starting job scraping pipeline...")
        logger.info("=" * 50)
        
        stats = {
            'timestamp': datetime.now().isoformat(),
            'total_scraped': 0,
            'total_filtered': 0,
            'total_new': 0,
            'total_sent': 0,
            'errors': []
        }
        
        # Step 1: SCRAPE from all sources
        all_jobs = []
        for scraper_name, scraper in self.scrapers.items():
            try:
                logger.info(f"\n📥 Scraping from {scraper_name}...")
                jobs = scraper.scrape()
                all_jobs.extend(jobs)
                stats['total_scraped'] += len(jobs)
                logger.info(f"   ✓ Got {len(jobs)} jobs")
            except Exception as e:
                error_msg = f"Scraper error ({scraper_name}): {e}"
                logger.error(error_msg)
                stats['errors'].append(error_msg)
        
        # Step 2: PROCESS - Filter and extract tags
        logger.info(f"\n🧠 Processing {len(all_jobs)} jobs...")
        filtered_jobs, _ = self.processor.process_jobs(all_jobs)
        stats['total_filtered'] = len(filtered_jobs)
        logger.info(f"   ✓ Filtered to {len(filtered_jobs)} relevant jobs")
        
        # Step 3: DEDUPLICATE - Check database
        logger.info(f"\n🔍 Checking for duplicates...")
        new_jobs = []
        for job in filtered_jobs:
            if not self.db.job_exists(job['link']):
                new_jobs.append(job)
            else:
                logger.debug(f"   Duplicate: {job['title']}")
        
        stats['total_new'] = len(new_jobs)
        logger.info(f"   ✓ Found {len(new_jobs)} new jobs")
        
        # Step 4: SAVE to database
        logger.info(f"\n💾 Saving to database...")
        for job in new_jobs:
            self.db.add_job(job)
        logger.info(f"   ✓ Saved {len(new_jobs)} new jobs")
        
        # Step 5: SEND via Telegram
        logger.info(f"\n📤 Sending to Telegram...")
        sent_count = self.send_jobs_batch(new_jobs)
        stats['total_sent'] = sent_count
        logger.info(f"   ✓ Sent {sent_count}/{len(new_jobs)} jobs")
        
        # Print summary
        logger.info("\n" + "=" * 50)
        logger.info("📊 PIPELINE SUMMARY")
        logger.info("=" * 50)
        logger.info(f"Total Scraped:  {stats['total_scraped']}")
        logger.info(f"Filtered:       {stats['total_filtered']}")
        logger.info(f"New Jobs:       {stats['total_new']}")
        logger.info(f"Sent to Chat:   {stats['total_sent']}")
        
        if stats['errors']:
            logger.warning("❌ Errors occurred:")
            for error in stats['errors']:
                logger.warning(f"   - {error}")
        
        logger.info("=" * 50 + "\n")
        
        return stats
    
    def send_jobs_batch(self, jobs: List[Dict]) -> int:
        """Send batch of jobs and mark as sent"""
        sent_count = 0
        
        for job in jobs:
            try:
                if self.notifier.send_job(job):
                    self.db.mark_sent(job.get('job_id', job['link']))
                    sent_count += 1
                    time.sleep(0.5)  # Rate limiting
            except Exception as e:
                logger.error(f"Error sending job {job.get('title')}: {e}")
        
        return sent_count
    
    def schedule_pipeline(self):
        """Schedule pipeline to run periodically"""
        logger.info(f"⏰ Scheduling pipeline every {SCRAPE_INTERVAL_HOURS} hours")
        
        # Schedule the job
        schedule.every(SCRAPE_INTERVAL_HOURS).hours.do(self.run_pipeline)
        
        logger.info("🔄 Scheduler started. Press Ctrl+C to stop.")
        
        # Keep scheduler running
        try:
            while True:
                schedule.run_pending()
                time.sleep(60)  # Check every minute
        except KeyboardInterrupt:
            logger.info("\n⏹️ Bot stopped by user")
    
    def get_stats(self) -> Dict:
        """Get current database statistics"""
        return self.db.get_stats()


def main():
    """Main entry point"""
    try:
        bot = JobScraperBot()
        
        # Option 1: Run once (for testing)
        bot.run_pipeline()
        
        # Option 2: Run on schedule (24/7) - uncomment to use
        # bot.schedule_pipeline()
        
    except KeyboardInterrupt:
        logger.info("Bot interrupted by user")
    except Exception as e:
        logger.critical(f"Fatal error: {e}", exc_info=True)


if __name__ == "__main__":
    main()
