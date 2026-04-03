# Job Scraper & Telegram Bot 🤖

Automated job scraper that collects internship/job opportunities from multiple sources and delivers them via Telegram.

## 🎯 Features

✅ **Multi-source scraping** - BD Jobs, LinkedIn, Facebook groups
✅ **Smart filtering** - Keyword-based relevance filtering  
✅ **Duplicate prevention** - SQLite database for tracking
✅ **Telegram notifications** - Real-time job alerts
✅ **Scheduled runs** - Automated 24/7 operation
✅ **Detailed logging** - Full audit trail

## 📋 Project Structure

```
bot/
├── bot.py                 # Main orchestrator
├── config.py              # Configuration
├── requirements.txt       # Dependencies
├── .env                   # Credentials (create from .env.template)
│
├── scrapers/              # Scraping layer
│   ├── base_scraper.py   # Abstract base class
│   └── bdjobs_scraper.py # BD Jobs implementation
│
├── processors/            # Processing layer (🧠 BRAIN)
│   └── job_processor.py  # Filter, extract tags, clean
│
├── database/              # Database layer
│   └── db_manager.py     # SQLite operations
│
├── notifier/              # Notification layer
│   └── telegram_notifier.py # Telegram Bot
│
├── logs/                  # Log files
└── data/                  # Database files
    └── jobs.db
```

## 🚀 Quick Start

### 1. Setup Telegram Bot

```bash
# Go to BotFather on Telegram
# /start → /newbot
# Get your TOKEN and CHAT_ID
```

### 2. Setup Python Environment

```bash
# Create virtual environment
python -m venv venv
source venv/Scripts/activate  # Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements.txt
```

### 3. Configure

```bash
# Copy template to .env
cp .env.template .env

# Edit .env with your credentials
# TELEGRAM_BOT_TOKEN=your_token
# TELEGRAM_CHAT_ID=your_chat_id
```

### 4. Run

```bash
# Option 1: Single run
python bot.py  # Scrape, process, send

# Option 2: Scheduled 24/7 (recommended)
# Edit bot.py - uncomment: bot.schedule_pipeline()
python bot.py
```

## 📊 Data Flow

```
[BD Jobs] + [LinkedIn] + [Facebook]
    ↓
[Scraper Layer] - Collect raw data
    ↓
[Processor] - Filter, extract tags
    ↓
[Database] - Check duplicates
    ↓
[Telegram] - Send notifications
    ↓
[DB] - Store sent jobs
```

## 🎨 Telegram Message Format

```
📌 Python Developer Internship

Company: Tech Corp
Type: Internship
Location: Dhaka, Bangladesh
Salary: 0-10k BDT

Tags: python, internship, remote
Source: bdjobs.com

📎 Link: [View Job]
```

## 🔥 Key Components

### Job Processor (Brain 🧠)
- **Keyword filtering** - Include/exclude logic
- **Tag extraction** - Auto-detect tech stack
- **Text cleaning** - Normalize data
- **NLP ready** - Placeholder for ML filtering

### Database (DBManager)
- **Jobs table** - Store collected jobs
- **Statistics** - Track daily metrics
- **Deduplication** - Avoid sending duplicates
- **SQLite** - No external dependencies

### Telegram Notifier
- **Formatted messages** - HTML rich text
- **Batch sending** - Efficient notification
- **Error handling** - Graceful failures
- **Rate limiting** - Respect Telegram limits

## 📈 Phases

| Phase | Goal | Status |
|-------|------|--------|
| Phase 1 | Basic MVP | ⏳ Now |
| Phase 2 | Multi-source | 🔲 Next |
| Phase 3 | Advanced DB | 🔲 Future |
| Phase 4 | ML Filtering | 🔲 Later |

## 🐛 Troubleshooting

### Bot not sending messages?
- Check TELEGRAM_BOT_TOKEN and TELEGRAM_CHAT_ID in .env
- Test: `python -c "from bot import *; bot.notifier.send_message('test')"`

### No jobs found?
- Check if source website still exists
- Verify request headers (User-Agent)
- Check HTML selectors in scraper

### Getting duplicates?
- Database path correct?
- Check `data/jobs.db` exists

## 🎓 Learning Outcomes

This project teaches:
- ✅ Web scraping (static + dynamic)
- ✅ Data processing & filtering
- ✅ Database operations (SQLite)
- ✅ Bot development
- ✅ Scheduling & automation
- ✅ Error handling & logging
- ✅ System design

## 💡 Future Features

- [ ] LinkedIn scraper (Selenium)
- [ ] Facebook group scraper
- [ ] NLP-based filtering
- [ ] PostgreSQL support
- [ ] Web dashboard
- [ ] Job recommendations
- [ ] User preferences
- [ ] Analytics

## 📞 Support

For issues or questions:
1. Check logs in `logs/bot.log`
2. Verify `.env` configuration
3. Test scrapers individually

## 📝 License

Open source - Use freely!

---

**Remember**: Start with one source, get it working, then expand. "Done is better than perfect." 🚀
