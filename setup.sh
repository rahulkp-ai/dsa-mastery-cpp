#!/usr/bin/env bash
set -e

echo "🚀 Setting up DSA-Mastery..."

# Python check
python3 --version || { echo "Python 3 required"; exit 1; }

# Install dependencies
pip install -r requirements.txt

# Create local config
cp .env.example .env 2>/dev/null || true

echo "✅ Setup complete! Run: jupyter lab notebooks/"
