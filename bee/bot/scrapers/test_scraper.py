"""
Test Scraper - Returns dummy job data for testing
Useful for verifying the pipeline works without websites
"""
from .base_scraper import BaseScraper
from typing import List, Dict
import logging

logger = logging.getLogger(__name__)

class TestScraper(BaseScraper):
    """Test scraper with dummy data"""
    
    def __init__(self):
        super().__init__("test-scraper")
    
    def scrape(self) -> List[Dict]:
        """Return test jobs"""
        self.jobs = [
            {
                'title': 'Python Developer Internship',
                'company': 'TechCorp BD',
                'link': 'https://example.com/job1',
                'location': 'Dhaka, Bangladesh',
                'salary': '5,000-10,000 BDT',
                'description': 'Looking for Python and Django developer for internship program',
                'source': 'test'
            },
            {
                'title': 'Junior Backend Engineer - Django & FastAPI',
                'company': 'Startup Hub',
                'link': 'https://example.com/job2',
                'location': 'Remote',
                'salary': '15,000-25,000 BDT',
                'description': 'Entry level position for Django/FastAPI developer',
                'source': 'test'
            },
            {
                'title': 'Senior Angular Developer - 10+ Years',
                'company': 'Enterprise Corp',
                'link': 'https://example.com/job3',
                'location': 'Dhaka',
                'salary': '100,000+ BDT',
                'description': 'We need an experienced Angular developer with 10+ years experience',
                'source': 'test'
            },
            {
                'title': 'Frontend Intern - HTML, CSS, JavaScript',
                'company': 'Digital Agency',
                'link': 'https://example.com/job4',
                'location': 'Dhaka',
                'salary': '3,000-5,000 BDT',
                'description': 'Looking for HTML, CSS and JavaScript intern',
                'source': 'test'
            }
        ]
        
        logger.info(f"Test scraper returned {len(self.jobs)} dummy jobs")
        return self.jobs
