"""
Database Manager - Handles all database operations
Supports SQLite (MVP) and PostgreSQL (Advanced)
"""
import sqlite3
import json
from datetime import datetime
from typing import List, Dict, Optional
import os

class DBManager:
    def __init__(self, db_path: str = "data/jobs.db"):
        self.db_path = db_path
        self._ensure_db_file_exists()
        self.conn = None
        self.init_db()

    def _ensure_db_file_exists(self):
        """Ensure directory exists for database"""
        os.makedirs(os.path.dirname(self.db_path) or ".", exist_ok=True)

    def init_db(self):
        """Initialize database with required tables"""
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        
        # Jobs table
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS jobs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            job_id TEXT UNIQUE NOT NULL,
            title TEXT NOT NULL,
            company TEXT NOT NULL,
            type TEXT,
            link TEXT UNIQUE NOT NULL,
            location TEXT,
            salary TEXT,
            description TEXT,
            tags TEXT,
            source TEXT,
            created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
            sent_at TIMESTAMP,
            is_sent BOOLEAN DEFAULT 0
        )
        ''')
        
        # Statistics table
        cursor.execute('''
        CREATE TABLE IF NOT EXISTS statistics (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            total_scraped INTEGER DEFAULT 0,
            total_filtered INTEGER DEFAULT 0,
            total_sent INTEGER DEFAULT 0,
            date DATE DEFAULT CURRENT_DATE,
            UNIQUE(date)
        )
        ''')
        
        conn.commit()
        conn.close()

    def add_job(self, job: Dict) -> bool:
        """Add job to database, return True if inserted (not duplicate)"""
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        
        try:
            cursor.execute('''
            INSERT INTO jobs 
            (job_id, title, company, type, link, location, salary, description, tags, source)
            VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)
            ''', (
                job.get('job_id', job['link']),  # Use link as ID if job_id not provided
                job['title'],
                job['company'],
                job.get('type'),
                job['link'],
                job.get('location'),
                job.get('salary'),
                job.get('description'),
                json.dumps(job.get('tags', [])),
                job.get('source', 'unknown')
            ))
            conn.commit()
            return True
        except sqlite3.IntegrityError:
            # Duplicate job
            return False
        finally:
            conn.close()

    def mark_sent(self, job_id: str) -> bool:
        """Mark job as sent via Telegram"""
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        
        cursor.execute('''
        UPDATE jobs 
        SET is_sent = 1, sent_at = CURRENT_TIMESTAMP 
        WHERE job_id = ?
        ''', (job_id,))
        
        conn.commit()
        conn.close()
        return cursor.rowcount > 0

    def get_unsent_jobs(self) -> List[Dict]:
        """Get all jobs not yet sent"""
        conn = sqlite3.connect(self.db_path)
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
        
        cursor.execute('''
        SELECT * FROM jobs WHERE is_sent = 0 ORDER BY created_at DESC
        ''')
        
        jobs = [dict(row) for row in cursor.fetchall()]
        conn.close()
        return jobs

    def job_exists(self, link: str) -> bool:
        """Check if job already exists"""
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        
        cursor.execute('SELECT 1 FROM jobs WHERE link = ?', (link,))
        exists = cursor.fetchone() is not None
        
        conn.close()
        return exists

    def get_all_jobs(self, limit: int = 100) -> List[Dict]:
        """Get recent jobs"""
        conn = sqlite3.connect(self.db_path)
        conn.row_factory = sqlite3.Row
        cursor = conn.cursor()
        
        cursor.execute('''
        SELECT * FROM jobs ORDER BY created_at DESC LIMIT ?
        ''', (limit,))
        
        jobs = [dict(row) for row in cursor.fetchall()]
        conn.close()
        return jobs

    def get_stats(self) -> Dict:
        """Get database statistics"""
        conn = sqlite3.connect(self.db_path)
        cursor = conn.cursor()
        
        cursor.execute('SELECT COUNT(*) FROM jobs')
        total_jobs = cursor.fetchone()[0]
        
        cursor.execute('SELECT COUNT(*) FROM jobs WHERE is_sent = 1')
        sent_jobs = cursor.fetchone()[0]
        
        cursor.execute('''
        SELECT COUNT(*) FROM jobs WHERE created_at >= datetime('now', '-1 day')
        ''')
        recent_jobs = cursor.fetchone()[0]
        
        conn.close()
        
        return {
            'total_jobs': total_jobs,
            'sent_jobs': sent_jobs,
            'recent_24h': recent_jobs,
            'pending': total_jobs - sent_jobs
        }
