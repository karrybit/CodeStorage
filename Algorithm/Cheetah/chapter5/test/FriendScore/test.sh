#!/bin/zsh

read number

CASE_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/test/FriendScore
CASE_NUMBER="example$number.txt"

case $number in
[0-4]) cat $CASE_PATH/$CASE_NUMBER;;
*) echo "The test case number is between 0 and 4. your input is $number";;
esac