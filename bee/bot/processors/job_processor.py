"""
Job Processor - Filters and processes job data
The BRAIN of the system 🔥
"""
import logging
import re
from typing import List, Dict, Tuple
from config import KEYWORDS_INCLUDE, KEYWORDS_EXCLUDE

logger = logging.getLogger(__name__)

class JobProcessor:
    """Process and filter jobs"""
    
    def __init__(self, keywords_include: List[str] = None, 
                 keywords_exclude: List[str] = None):
        self.keywords_include = keywords_include or KEYWORDS_INCLUDE
        self.keywords_exclude = keywords_exclude or KEYWORDS_EXCLUDE
    
    def process_jobs(self, jobs: List[Dict]) -> Tuple[List[Dict], int]:
        """
        Process jobs: clean, filter, extract tags
        Returns: (filtered_jobs, filtered_count)
        """
        filtered_jobs = []
        
        for job in jobs:
            if self.is_relevant(job):
                job['tags'] = self.extract_tags(job)
                filtered_jobs.append(job)
        
        logger.info(f"Filtered {len(filtered_jobs)} relevant jobs from {len(jobs)} total")
        return filtered_jobs, len(jobs)
    
    def is_relevant(self, job: Dict) -> bool:
        """Check if job matches filter criteria"""
        text = f"{job.get('title', '')} {job.get('description', '')}".lower()
        
        # Check excludes first (negative filtering)
        for keyword in self.keywords_exclude:
            if keyword.lower() in text:
                logger.debug(f"Excluded job: {job.get('title')} (matched exclude: {keyword})")
                return False
        
        # Check includes (positive filtering)
        for keyword in self.keywords_include:
            if keyword.lower() in text:
                return True
        
        logger.debug(f"Rejected job: {job.get('title')} (no matching keywords)")
        return False
    
    def extract_tags(self, job: Dict) -> List[str]:
        """Extract relevant tags from job"""
        tags = []
        text = f"{job.get('title', '')} {job.get('description', '')}".lower()
        
        # Programming languages/frameworks
        tech_keywords = {
            'python': ['python', 'django', 'fastapi', 'flask'],
            'javascript': ['javascript', 'nodejs', 'react', 'vue', 'angular'],
            'java': ['java', 'spring', 'maven'],
            'web': ['html', 'css', 'web developer', 'frontend', 'backend'],
            'data': ['data engineer', 'data scientist', 'ml', 'machine learning'],
            'devops': ['devops', 'docker', 'kubernetes', 'ci/cd'],
        }
        
        for category, keywords in tech_keywords.items():
            for keyword in keywords:
                if keyword in text:
                    tags.append(category)
                    break
        
        # Job type tags
        if any(word in text for word in ['intern', 'internship', 'trainee']):
            tags.append('internship')
        
        if any(word in text for word in ['remote', 'work from home']):
            tags.append('remote')
        
        if any(word in text for word in ['entry level', 'junior', 'fresher']):
            tags.append('entry-level')
        
        return list(set(tags))  # Remove duplicates
    
    def clean_text(self, text: str) -> str:
        """Clean text data"""
        # Remove extra whitespace
        text = re.sub(r'\s+', ' ', text)
        # Remove special characters (keep basic punctuation)
        text = re.sub(r'[^\w\s\-.,:]', '', text)
        return text.strip()


class NLPProcessor(JobProcessor):
    """Advanced NLP-based processor (Phase 4)
    Future: Use NLP/ML for smarter filtering
    """
    
    def is_relevant_ml(self, job: Dict) -> bool:
        """ML-based relevance scoring (placeholder for future)"""
        # TODO: Implement with sklearn, spacy, or transformer models
        pass


if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO)
    
    processor = JobProcessor()
    
    # Test jobs
    test_jobs = [
        {
            'title': 'Python Developer Internship',
            'company': 'Tech Corp',
            'link': 'http://example.com/1',
            'description': 'Looking for Django developer',
            'source': 'test'
        },
        {
            'title': 'Senior Java Engineer',
            'company': 'Old Inc',
            'link': 'http://example.com/2',
            'description': 'Need 10+ years experience',
            'source': 'test'
        }
    ]
    
    filtered, total = processor.process_jobs(test_jobs)
    for job in filtered:
        print(f"✓ {job['title']} - Tags: {job['tags']}")
