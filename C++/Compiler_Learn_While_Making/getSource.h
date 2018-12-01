#include <stdio.h>
#ifndef TBL
#define TBL
#include "table.h"
#endif
// 名前の最大長さ
#define MAXNAME 31

// キーや文字の種類（名前）
typedef enum keys {
    // 予約語の名前ここから
    Begin, End,
    If, Then,
    While, Do,
    Ret, Func,
    Var, Const, Odd,
    Write, WriteLn,
    end_of_KeyWd,
    // 予約語の名前ここまで

    // 演算子と区切り記号の名前
    Plus, Minus,
    Mult, Div,
    Lparen, Rparen,
    Equal, Lss, Gtr,
    NotEq, LssEq, GtrEq,
    Comma, Period, Semicolon,
    Asssign,
    end_of_KeySym,
    // 演算子と区切り記号の名前ここまで

    // トークンの種類ここから
    Id, Num, nul,
    end_of_Token,
    // トークンの種類ここまで

    // 上記以外の文字の種類
    letter, digit, colon, others
} KeyId;

// トークンの型
typedef struct token {
    KeyId kind;             // トークンの種類かキーの名前
    union {
        char id[MAXNAME];   // Identifierの時、その名前
        int value;          // Numの時、その値
    } u;
} Token;

// 次のトークンを読んで返す
Token nextToken();

// t.kind == k のチェック
// t.kind == k なら、次のトークンを読んで返す
// t.kind != k なら、エラーメッセージを出し、tとkが共に記号または予約語なら
// tを捨て、次のトークンを読んで返す（tをkで置き換えたことになる）
// それ以外の場合、kを挿入したことにして、tを返す
Token checkGet(Token t, KeyId k);

// ソースファイルのopen
int openSource(char fineName[]);

// ソースファイルのclose
void closeSource();

// テーブルの初期設定、texファイルの初期設定
void initSource();

// ソースの最後のチェック、texファイルの最終設定
void finalSource();

// 型エラーを、texファイルに出力
void errorType(char *m);

// keyString(k)を.texファイルに挿入
void errorInsert(KeyId k);

// 名前がないとのメッセージを.texファイルに挿入
void errorMissingId();

// 演算子がないとのメッセージを.texファイルに挿入
void errorMissingOp();

// 今読んだトークンを読み捨て（.texファイルに出力）
void errorDelete();

// エラーメッセージを.texファイルに出力
void errorMessage(char *m);

// エラーメッセージを出力し、コンパイル終了
void errorF(char *m);

// エラーの個数を返す
int errorN();

// 現トークン（Id）の種類をセット（.txtファイル出力のため）
void setIdKind(KindT k);
