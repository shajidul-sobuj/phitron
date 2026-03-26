import requests
from bs4 import BeautifulSoup
from .base import PlatformFetcher
from config import HEADERS, KEYWORDS

class CourseraFetcher(PlatformFetcher):
    def fetch_courses(self):
        # Search specifically for "Free" difficulty/product type
        base_url = "https://www.coursera.org/courses?query=free&productDifficultyLevel=Beginner"
        courses = []
        
        # Note: Coursera is very dynamic. In a full production env, 
        # using their Partner API is better. For this bot, we check if
        # we can parse the initial HTML or use a fallback list.
        # Assuming we can parse standard class names (these change often):
        
        try:
            resp = requests.get(base_url, headers=HEADERS, timeout=10)
            soup = BeautifulSoup(resp.text, 'html.parser')
            
            # This selector is hypothetical as Coursera uses dynamic classes (css-12345)
            # A robust strategy scans for aria-labels or specific text patterns
            found_items = soup.find_all('a', href=True)
            
            for item in found_items:
                title_candidate = item.get_text(strip=True)
                href = item.get('href')
                if not href or not title_candidate:
                    continue
                if href.startswith("http"):
                    link = href
                else:
                    link = "https://www.coursera.org" + href
                
                # Filter specifically for our keywords in the link or text
                if "/learn/" in link and any(k.lower() in title_candidate.lower() for k in KEYWORDS):
                     courses.append({
                        'title': title_candidate.strip(),
                        'link': link,
                        'platform': 'Coursera'
                    })
                    
        except Exception as e:
            print(f"Coursera Fetch Error: {e}")
            
        return courses[:5] # Limit spam