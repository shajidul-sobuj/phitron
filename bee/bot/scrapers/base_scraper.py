"""
Base Scraper Class - Abstract base for all scrapers
Provides common functionality for different scraping sources
"""
from abc import ABC, abstractmethod
from typing import List, Dict
import logging

logger = logging.getLogger(__name__)

class BaseScraper(ABC):
    """Abstract base class for all scrapers"""
    
    def __init__(self, name: str):
        self.name = name
        self.jobs = []
        
    @abstractmethod
    def scrape(self) -> List[Dict]:
        """
        Main scraping method
        Should return list of job dictionaries with:
        {
            'title': str,
            'company': str,
            'link': str,
            'location': str (optional),
            'salary': str (optional),
            'description': str (optional),
            'source': str (source name)
        }
        """
        pass
    
    def get_jobs(self) -> List[Dict]:
        """Get scraped jobs"""
        return self.jobs
    
    def format_job(self, title: str, company: str, link: str, 
                   location: str = None, salary: str = None,
                   description: str = None) -> Dict:
        """Format job data into standard format"""
        return {
            'title': title.strip() if title else '',
            'company': company.strip() if company else '',
            'link': link.strip() if link else '',
            'location': location.strip() if location else 'Not specified',
            'salary': salary.strip() if salary else 'Not specified',
            'description': description.strip() if description else '',
            'source': self.name
        }
    
    def validate_job(self, job: Dict) -> bool:
        """Validate job has required fields"""
        required_fields = ['title', 'company', 'link']
        return all(job.get(field) for field in required_fields)
