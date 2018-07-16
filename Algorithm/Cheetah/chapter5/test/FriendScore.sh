#!/bin/zsh

read number

case $number in
0) sed -n '4, 7p' ./test/FriendScore.txt ;;
1) sed -n '13, 16p' ./test/FriendScore.txt ;;
2) sed -n '22, 27p' ./test/FriendScore.txt ;;
3) sed -n '33, 43p' ./test/FriendScore.txt ;;
4) sed -n '49, 64p' ./test/FriendScore.txt ;;
*) echo "The test case number is between 0 and 4. your input is $number" ;;
esac
