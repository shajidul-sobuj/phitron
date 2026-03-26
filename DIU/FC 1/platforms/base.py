from abc import ABC, abstractmethod

class PlatformFetcher(ABC):
    @abstractmethod
    def fetch_courses(self):
        """Returns a list of dicts: {'title', 'link', 'platform'}"""
        pass