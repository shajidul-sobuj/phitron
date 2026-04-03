#!/bin/bash
# Setup Script - Run once to initialize everything

echo "🤖 Job Scraper Bot Setup"
echo "========================"
echo ""

# Check Python
echo "1️⃣  Checking Python..."
python --version

# Create virtual environment
echo ""
echo "2️⃣  Creating virtual environment..."
python -m venv venv

# Activate and install
echo ""
echo "3️⃣  Installing dependencies..."
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "win32" ]]; then
    # Windows
    source venv/Scripts/activate
else
    # Linux/Mac
    source venv/bin/activate
fi

pip install --upgrade pip
pip install -r requirements.txt

# Create .env
echo ""
echo "4️⃣  Setting up configuration..."
if [ ! -f .env ]; then
    cp .env.template .env
    echo "   ✓ Created .env file"
    echo "   → Edit .env with your Telegram credentials"
else
    echo "   ✓ .env already exists"
fi

# Create directories
echo ""
echo "5️⃣  Creating directories..."
mkdir -p data logs
echo "   ✓ data/ directory"
echo "   ✓ logs/ directory"

echo ""
echo "✅ Setup Complete!"
echo ""
echo "📝 TODO:"
echo "   [ ] Edit .env and add your bot token"
echo "   [ ] Run: python test_components.py"
echo "   [ ] Run: python bot.py"
echo ""
