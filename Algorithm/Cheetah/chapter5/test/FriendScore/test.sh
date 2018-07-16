#!/bin/zsh

read NUMBER

CASE_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/test/FriendScore
EXEC_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/FriendScore.o
CASE_FILE="example$NUMBER.txt"
LINES=0

case $NUMBER in
[0-4])
    LINES=`cat $CASE_PATH/$CASE_FILE | wc -l`
    LINES=$[$LINES - 1];;
*);;
esac


EXPECT=`grep "Return" $CASE_PATH/$CASE_FILE | awk '{print $2}'`

case $NUMBER in
[0-4])
    ANSWER=`sed -n "1, ${LINES}p" $CASE_PATH/$CASE_FILE | $EXEC_PATH`
    RESULT="case: $NUMBER, expect: $EXPECT, answer: $ANSWER"
    if [ ${EXPECT} = ${ANSWER} ];
        then echo "$RESULT, result: Success"
        else echo "$RESULT, result: Failure"
    fi
;;
*) echo "The test case number is between 0 and 4. your input is $NUMBER";;
esac