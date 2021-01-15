#!/bin/bash

# GitHub initial commit script
# Make sure repository is created at github.com

echo "Running GitHub Script..."

git init
git status
git add *
git commit -m "Initial Commit"

echo "Please type the repository name..."
read varname

git remote add origin git@github.com:michael-j-cho/$varname.git
git branch -M main
git push -u origin main

echo "Done!"