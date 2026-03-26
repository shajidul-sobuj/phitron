import time
# import schedule
from database import init_db, is_duplicate, mark_as_sent
from config import KEYWORDS
from utils.notifier import send_telegram_alert

# Import Fetchers
from platforms.udemy import UdemyFetcher
from platforms.coursera import CourseraFetcher
from platforms.fcc import FCCFetcher

def job():
    print(f"--- Starting Scan: {time.ctime()} ---")
    
    fetchers = [
        UdemyFetcher(),
        FCCFetcher(),
        CourseraFetcher()
    ]
    
    for fetcher in fetchers:
        try:
            # 1. Fetch
            found_courses = fetcher.fetch_courses()
            
            count = 0
            for course in found_courses:
                # Spam Control: Max 5 per platform per run
                if count >= 5: 
                    break
                
                # 2. Filter & Deduplicate
                if not is_duplicate(course['link']):
                    
                    # 3. Notify
                    success = send_telegram_alert(course, KEYWORDS)
                    
                    # 4. Update DB
                    if success:
                        mark_as_sent(course['link'], course['title'], course['platform'])
                        print(f"Sent: {course['title']}")
                        count += 1
                        
        except Exception as e:
            print(f"Critical Error in fetch loop: {e}")

    print("--- Scan Complete ---")

if __name__ == "__main__":
    init_db()
    
    # Run immediately on startup
    job()
    
    # Schedule every 4 hours
    # schedule.every(4).hours.do(job)
    
    print("Bot is running...")
    while True:
        #schedule.run_pending()
        time.sleep(60)