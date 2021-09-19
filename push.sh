#!/bin/bash
git add .
export EDITOR='vim' 
git commit -a
read -p "press enter to push."
git push "https://loganer%40vivaldi.net:$(cat ../git_token.txt)@github.com/Tarcaxoxide/Sauce.git"
