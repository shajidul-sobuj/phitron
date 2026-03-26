import sqlite3
from datetime import datetime
from config import DB_FILE

def init_db():
    conn = sqlite3.connect(DB_FILE)
    c = conn.cursor()
    c.execute('''
        CREATE TABLE IF NOT EXISTS sent_courses (
            url TEXT PRIMARY KEY,
            title TEXT,
            platform TEXT,
            sent_at DATETIME
        )
    ''')
    conn.commit()
    conn.close()

def is_duplicate(url):
    conn = sqlite3.connect(DB_FILE)
    c = conn.cursor()
    c.execute("SELECT 1 FROM sent_courses WHERE url = ?", (url,))
    result = c.fetchone()
    conn.close()
    return result is not None

def mark_as_sent(url, title, platform):
    conn = sqlite3.connect(DB_FILE)
    c = conn.cursor()
    try:
        c.execute("INSERT INTO sent_courses (url, title, platform, sent_at) VALUES (?, ?, ?, ?)",
                  (url, title, platform, datetime.now()))
        conn.commit()
    except sqlite3.IntegrityError:
        pass # Already exists
    conn.close()