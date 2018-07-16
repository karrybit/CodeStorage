#!/bin/zsh

# チャプター番号
CHAPTER=chapter$1
# 問題名
PROBLEM=$2
# ケース番号
TEST_NUMBER=$3
# テストケースのパス
TEST_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/test
# 実行ファイルのパス
EXEC_PATH=$HOME/Develop/CodeStorage/Algorithm/Cheetah/$CHAPTER

# テストケースの数を取得するため、ファイル数をカウント
FILES=`ls -1 $TEST_PATH/$PROBLEM | wc -l`
FILES=$[$FILES - 1]

if [ `echo $TEST_NUMBER | grep "[0-${FILES}]"` ]; then
# 引数がケース番号の場合
    CASE_FILE="example$TEST_NUMBER.txt"
    LINES=0
    # ケースの行数を取得
    LINES=`cat $TEST_PATH/$PROBLEM/$CASE_FILE | wc -l`
    # 期待値を記述しているためケースの記述数分に調整する
    LINES=$[$LINES - 1]
    # 期待値を取得
    # TODO: 1文字ではなく、複数行にまたがるような期待値にも対応
    EXPECT=`grep "Return" $TEST_PATH/$PROBLEM/$CASE_FILE | awk '{print $2}'`

elif [ $TEST_NUMBER = "all" ]; then
# 引数がallの場合
    echo "test all cases."

else
    echo "👹 The test case number is between 0 and 4."
    echo "👹 your input is [$3]"
    exit 0;
fi

if [ `echo $TEST_NUMBER | grep "[0-${FILES}]"` ]; then
# 引数がケース番号の場合
    # テストの実行
    ANSWER=`sed -n "1, ${LINES}p" $TEST_PATH/$PROBLEM/$CASE_FILE | $EXEC_PATH/$PROBLEM.o`

    if [ ${EXPECT} = ${ANSWER} ];
    # テスト結果が期待値の突合結果を出力
        then echo "🚀 case: $TEST_NUMBER, expect: $EXPECT, answer: $ANSWER, result: ☀️ Success"
        else echo "🚀 case: $TEST_NUMBER, expect: $EXPECT, answer: $ANSWER, result: ⛈ Failure"
    fi

else
# 引数がallの場合
    for i in $(seq 0 ${FILES})
    do
        # 0から4まですべて行う
        sh $TEST_PATH/test.sh $1 $2 $i
    done
fi