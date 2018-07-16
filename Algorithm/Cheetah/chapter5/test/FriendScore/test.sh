#!/bin/zsh



CASE_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/test/FriendScore
EXEC_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/FriendScore.o

if [ `echo $1 | grep '[0-4]'` ]; then
    CASE_FILE="example$1.txt"
    LINES=0
    LINES=`cat $CASE_PATH/$CASE_FILE | wc -l`
    LINES=$[$LINES - 1]
    EXPECT=`grep "Return" $CASE_PATH/$CASE_FILE | awk '{print $2}'`

elif [ $1 = "all" ]; then
    echo "test all cases."
else
    echo "👹 The test case number is between 0 and 4. your input is $1"
    exit 0;
fi

if [ `echo $1 | grep '[0-4]'` ]; then
    ANSWER=`sed -n "1, ${LINES}p" $CASE_PATH/$CASE_FILE | $EXEC_PATH`
    RESULT="🚀 case: $1, expect: $EXPECT, answer: $ANSWER"
    if [ ${EXPECT} = ${ANSWER} ];
        then echo "$RESULT, result: ☀️ Success"
        else echo "$RESULT, result: ⛈ Failure"
    fi
else
    for i in 0 1 2 3 4
    do
        sh $CASE_PATH/test.sh $i
    done
fi