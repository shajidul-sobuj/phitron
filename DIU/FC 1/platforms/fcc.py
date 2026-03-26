import requests
import xml.etree.ElementTree as ET
from .base import PlatformFetcher
from config import KEYWORDS

class FCCFetcher(PlatformFetcher):
    def fetch_courses(self):
        url = "https://www.freecodecamp.org/news/rss/"
        courses = []
        try:
            resp = requests.get(url, timeout=10)
            root = ET.fromstring(resp.content)
            
            for item in root.findall('./channel/item'):
                title_elem = item.find('title')
                link_elem = item.find('link')
                if title_elem is None or link_elem is None:
                    continue
                title = title_elem.text or ""
                link = link_elem.text or ""
                if not title or not link:
                    continue
                
                # Look for "Course" in title to differentiate from articles
                if "course" in title.lower() and any(k.lower() in title.lower() for k in KEYWORDS):
                    courses.append({
                        'title': title,
                        'link': link,
                        'platform': 'freeCodeCamp'
                    })
        except Exception as e:
            print(f"FCC Fetch Error: {e}")
            
        return courses