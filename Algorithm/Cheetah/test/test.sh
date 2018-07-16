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
FILES=`ls -1 $TEST_PATH/$PROBLEM/Input | wc -l`
FILES=$[$FILES - 1]

if [ `echo $TEST_NUMBER | grep "[0-${FILES}]"` ]; then
    :
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
    touch $TEST_PATH/temp.txt
    cat $TEST_PATH/$PROBLEM/Input/example$TEST_NUMBER.txt | $EXEC_PATH/$PROBLEM.o > $TEST_PATH/temp.txt

    cmp -s $TEST_PATH/temp.txt $TEST_PATH/$PROBLEM/Output/example$TEST_NUMBER.txt

    if test $? -eq 0 ;
    # テスト結果が期待値の突合結果を出力
        then
            echo "🚀 case: $TEST_NUMBER"
            echo "📋 expect:"
            cat $TEST_PATH/$PROBLEM/Output/example$TEST_NUMBER.txt
            echo "🖌 answer:"
            cat $TEST_PATH/temp.txt
            echo "💡 result: ☀️ Success"
        else
            echo "🚀 case: $TEST_NUMBER"
            echo "🚓 expect:"
            cat $TEST_PATH/$PROBLEM/Output/example$TEST_NUMBER.txt
            echo "👨‍🎓 answer:"
            cat $TEST_PATH/temp.txt
            echo "💡 result: ⛈ Failure"
    fi

    echo ""
    rm -f $TEST_PATH/temp.txt
else
# 引数がallの場合
    for i in $(seq 0 ${FILES})
    do
        # 0から4まですべて行う
        sh $TEST_PATH/test.sh $1 $2 $i
    done
fi