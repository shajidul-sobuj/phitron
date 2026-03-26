import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from .base import PlatformFetcher
from config import HEADERS, KEYWORDS

class UdemyFetcher(PlatformFetcher):
    def fetch_courses(self):
        url = "https://www.discudemy.com/all"
        courses = []
        try:
            resp = requests.get(url, headers=HEADERS, timeout=10)
            soup = BeautifulSoup(resp.text, 'html.parser')
            
            # Select course cards
            items = soup.select('section.card')
            
            for item in items[:10]: # Check newest 10
                title_tag = item.select_one('.card-header')
                link_tag = item.select_one('a.card-header')
                
                if title_tag and link_tag:
                    title = title_tag.get_text(strip=True)
                    # Simple keyword filter
                    if any(k.lower() in title.lower() for k in KEYWORDS):
                        # DiscUdemy has an intermediate page, usually acceptable to link
                        # For production, you might want to scrape the deep link
                        link = urljoin(url, link_tag['href']) 
                        
                        courses.append({
                            'title': title,
                            'link': link,
                            'platform': 'Udemy'
                        })
        except Exception as e:
            print(f"Udemy Fetch Error: {e}")
            
        return courses