"""
BD Jobs Scraper - Scrapes jobs from bdjobs.com
Static scraper using requests + BeautifulSoup
"""
import requests
from bs4 import BeautifulSoup
import logging
from typing import List, Dict
from .base_scraper import BaseScraper
from config import REQUEST_TIMEOUT, USER_AGENT

logger = logging.getLogger(__name__)

class BDJobsScraper(BaseScraper):
    """Scraper for bdjobs.com"""
    
    def __init__(self):
        super().__init__("bdjobs.com")
        self.base_url = "https://www.bdjobs.com/jobsearch.asp"
        self.session = requests.Session()
        self.session.headers.update({'User-Agent': USER_AGENT})
    
    def scrape(self) -> List[Dict]:
        """Scrape jobs from bdjobs"""
        try:
            # Search for internship/entry-level jobs
            params = {
                'fcateg': 0,  # All categories
                'fskill': 'intern',  # Internship keyword
            }
            
            response = self.session.get(
                self.base_url,
                params=params,
                timeout=REQUEST_TIMEOUT
            )
            response.raise_for_status()
            
            soup = BeautifulSoup(response.content, 'html.parser')
            jobs = self._parse_jobs(soup)
            
            logger.info(f"Scraped {len(jobs)} jobs from {self.name}")
            self.jobs = jobs
            return jobs
            
        except requests.RequestException as e:
            logger.error(f"Error scraping {self.name}: {e}")
            return []
    
    def _parse_jobs(self, soup: BeautifulSoup) -> List[Dict]:
        """Parse job listings from HTML"""
        jobs = []
        
        # Locate job listing containers (adjust selector based on actual site structure)
        job_items = soup.find_all('div', class_='joblist')  # Adjust as needed
        
        for item in job_items:
            try:
                title_elem = item.find('h4')
                company_elem = item.find('span', class_='company')
                link_elem = item.find('a', href=True)
                location_elem = item.find('span', class_='location')
                
                if not all([title_elem, company_elem, link_elem]):
                    continue
                
                job = self.format_job(
                    title=title_elem.get_text(),
                    company=company_elem.get_text(),
                    link=link_elem['href'] if link_elem['href'].startswith('http') 
                         else 'https://www.bdjobs.com' + link_elem['href'],
                    location=location_elem.get_text() if location_elem else None
                )
                
                if self.validate_job(job):
                    jobs.append(job)
                    
            except (AttributeError, KeyError) as e:
                logger.debug(f"Error parsing job item: {e}")
                continue
        
        return jobs


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    scraper = BDJobsScraper()
    jobs = scraper.scrape()
    for job in jobs[:5]:
        print(job)
