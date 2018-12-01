#include "getSource.h"
#ifndef TBL
#define TBL
#include "table.h"
#endif
#include "codegen.h"

#define MINERROR 3      // エラーがこれ以下なら実行
#define FIRSTADDR 2     // 各ブロックの最初の変数のアドレス

static Token token;     // 次のトークンを入れておく

static void block(int pIndex);      // ブロックのコンパイル
                                    // pIndex はこのブロックの関数名のインデックス
static void constDecl();            // 定数宣言のコンパイル
static void varDecl();              // 変数宣言のコンパイル
static void funcDecl();             // 関数宣言のコンパイル
static void statement();            // 文のコンパイル
static void expression();           // 式のコンパイル
static void term();                 // 式の項のコンパイル
static void factor();               // 式の因子のコンパイル
static void condition();            // 条件式のコンパイル
static int isStBeginKey(Token t);   // トークンtは文の先頭のキーか？

int compile() {
    int i;
    printf("start compilation\n");
    initSource();               // getSourceの初期設定
    token = nextToken();        // 最初のトークン
    blockBegin(FIRSTADDR);      // これ以後の宣言は新しいブロックのもの

    block(0);                   // 0はダミー（主ブロックの関数名はない）
    finalSource();

    i = errorN();               // エラーメッセージの個数

    if (i != 0)
        printf("%d error\n", i);

    // listCode();  目的コードのリスト（必要なら）
    return i < MINERROR;        // エラーメッセージの個数が少ないかどうかの判定
}

void block(int pIndex) {            // pIndexはこのブロックの関数名のインデックス
    int backP;
    backP = genCodeV(jmp, 0);       // 内部関数を飛び越す命令、後でバックパッチ

    while (true) {                  // 宣言部のコンパイルを繰り返す
        switch (token.kind) {
        case Const:                 // 定数宣言部のコンパイル
            token = nextToken();
            constDecl();
            continue;
        case Var:                   // 変数宣言部のコンパイル
            token = nextToken();
            varDecl();
            continue;
        case Func:                  // 関数宣言部のコンパイル
            token = nextToken();
            funcDecl;
            continue;
        default:                    // それ以外なら宣言部は終わり
            break;
        }
        break;
    }

    backPatch(backP);               // 内部関数を飛び越す命令にパッチ
    changeV(pIndex, nextCode());    // この関数の開始番地を修正
    genCodeV(ict, frameL());        // このブロックの実行時の必要記憶域をとる命令
    statement();                    // このブロックの主文
    genCodeR();                     // リターン命令
    blockEnd();                     // ブロックが終わったことをtableに連絡
}


// 定数宣言のコンパイル
void constDecl() {
    Token temp;
    while (true) {
        if (token.kind == Id) {
            setIdKind(constId);     // 印字のための情報のセット
            temp = token;           // 名前を入れておく
            token = checkGet(nextToken(), Equal);   // 名前の次は"="のはず

            if (token.kind == Num)
                enterTconst(temp.u.id, token.u.value);  // 定数名と値をテーブルに
            else
                errorType("number");

            token = nextToken();

        } else
            errorMissingId();

        // 次がコンマなら定数宣言が続く
        if (token.kind != Comma) {
            // 次が名前ならコンマを忘れたことにする
            if (token.kind == Id) {
                errorInsert(Comma);
                continue;
            } else
                break;
        }

        token = nextToken();
    }

    token = checkGet(token, Semicolon);     // 最後は";"のはず
}
