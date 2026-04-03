"""
Telegram Notifier - Sends job notifications via Telegram Bot
"""
import logging
import asyncio
from typing import Dict, List
from telegram import Bot
from telegram.error import TelegramError

logger = logging.getLogger(__name__)

class TelegramNotifier:
    """Send notifications to Telegram"""
    
    def __init__(self, bot_token: str, chat_id: str):
        self.bot = Bot(token=bot_token)
        self.chat_id = chat_id
    
    def send_job(self, job: Dict) -> bool:
        """Send single job notification"""
        message = self._format_message(job)
        return self.send_message(message)
    
    def send_jobs_batch(self, jobs: List[Dict]) -> int:
        """Send multiple jobs, return count of successful sends"""
        sent_count = 0
        for job in jobs:
            if self.send_job(job):
                sent_count += 1
        return sent_count
    
    def send_message(self, text: str) -> bool:
        """Send raw message to Telegram"""
        try:
            # Use asyncio to handle the coroutine
            loop = asyncio.new_event_loop()
            asyncio.set_event_loop(loop)
            loop.run_until_complete(
                self.bot.send_message(
                    chat_id=self.chat_id,
                    text=text,
                    parse_mode='HTML'
                )
            )
            loop.close()
            logger.info(f"Message sent to Telegram")
            return True
        except TelegramError as e:
            logger.error(f"Failed to send Telegram message: {e}")
            return False
        except Exception as e:
            logger.error(f"Unexpected error sending message: {e}")
            return False
    
    def _format_message(self, job: Dict) -> str:
        """Format job into Telegram message"""
        message = f"""
<b>📌 {job.get('title', 'N/A')}</b>

<b>Company:</b> {job.get('company', 'N/A')}
<b>Type:</b> {job.get('type', 'Not specified')}
<b>Location:</b> {job.get('location', 'Not specified')}
<b>Salary:</b> {job.get('salary', 'Not specified')}

<b>Tags:</b> {', '.join(job.get('tags', []))}
<b>Source:</b> {job.get('source', 'N/A')}

<b>📎 Link:</b> <a href='{job.get('link', '#')}'>View Job</a>

---
        """.strip()
        return message
    
    def send_daily_summary(self, stats: Dict) -> bool:
        """Send daily statistics summary"""
        message = f"""
<b>📊 Daily Job Report</b>

📍 Total Scraped: {stats.get('total_scraped', 0)}
✅ Filtered: {stats.get('total_filtered', 0)}
📤 Sent: {stats.get('total_sent', 0)}
⏳ Date: Today

Stay tuned for more opportunities!
        """.strip()
        return self.send_message(message)


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    
    # Test notification
    notifier = TelegramNotifier(
        bot_token="YOUR_TOKEN",
        chat_id="YOUR_CHAT_ID"
    )
    
    test_job = {
        'title': 'Python Developer Internship',
        'company': 'Tech Corp',
        'type': 'Internship',
        'location': 'Dhaka, Bangladesh',
        'salary': '0-10k BDT',
        'tags': ['python', 'internship', 'remote'],
        'link': 'http://example.com',
        'source': 'bdjobs.com'
    }
    
    # notifier.send_job(test_job)
