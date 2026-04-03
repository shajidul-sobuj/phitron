@echo off
REM Setup Script for Windows - Run once to initialize everything

echo 🤖 Job Scraper Bot Setup
echo ========================
echo.

REM Check Python
echo 1️⃣  Checking Python...
python --version

REM Create virtual environment
echo.
echo 2️⃣  Creating virtual environment...
python -m venv venv

REM Activate and install
echo.
echo 3️⃣  Installing dependencies...
call venv\Scripts\activate.bat
pip install --upgrade pip
pip install -r requirements.txt

REM Create .env
echo.
echo 4️⃣  Setting up configuration...
if not exist .env (
    copy .env.template .env
    echo    ✓ Created .env file
    echo    ^→ Edit .env with your Telegram credentials
) else (
    echo    ✓ .env already exists
)

REM Create directories
echo.
echo 5️⃣  Creating directories...
if not exist data mkdir data
if not exist logs mkdir logs
echo    ✓ data\ directory
echo    ✓ logs\ directory

echo.
echo ✅ Setup Complete!
echo.
echo 📝 TODO:
echo    [ ] Edit .env and add your bot token
echo    [ ] Run: python test_components.py
echo    [ ] Run: python bot.py
echo.
pause
