#!/bin/zsh

# ケース名
CASE=$1
# テストケースのパス
TEST_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/test/$CASE
# 実行ファイルのパス
EXEC_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/chapter5/$CASE.o

if [ `echo $2 | grep '[0-4]'` ]; then
# 引数がケース番号の場合
    CASE_FILE="example$2.txt"
    LINES=0
    # ケースの行数を取得
    LINES=`cat $TEST_PATH/$CASE_FILE | wc -l`
    # 期待値を記述しているためケースの記述数分に調整する
    LINES=$[$LINES - 1]
    # 期待値を取得
    # TODO: 1文字ではなく、複数行にまたがるような期待値にも対応
    EXPECT=`grep "Return" $TEST_PATH/$CASE_FILE | awk '{print $2}'`

elif [ $2 = "all" ]; then
# 引数がallの場合
    echo "test all cases."

else
    echo "👹 The test case number is between 0 and 4. your input is $1"
    exit 0;
fi

if [ `echo $2 | grep '[0-4]'` ]; then
# 引数がケース番号の場合
    # テストの実行
    ANSWER=`sed -n "1, ${LINES}p" $TEST_PATH/$CASE_FILE | $EXEC_PATH`

    if [ ${EXPECT} = ${ANSWER} ];
    # テスト結果が期待値の突合結果を出力
        then echo "🚀 case: $2, expect: $EXPECT, answer: $ANSWER, result: ☀️ Success"
        else echo "🚀 case: $2, expect: $EXPECT, answer: $ANSWER, result: ⛈ Failure"
    fi

else
# 引数がallの場合
    # テストケースの数を取得するため、ファイル数をカウント
    FILES=`ls -1 $TEST_PATH | wc -l`
    FILES=$[$FILES - 2]
    for i in $(seq 0 ${FILES})
    do
        # 0から4まですべて行う
        sh $TEST_PATH/test.sh $CASE $i
    done
fi