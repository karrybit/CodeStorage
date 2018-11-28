#include "getSource.h"
#ifndef TBL
#define TBL
#include "table.h"
#endif
#include "codegen.h"

#define MINERROR 3      /* エラーがこれ以下なら実行 */
#define FIRSTADDR 2     /* 各ブロックの最初の変数のアドレス */

static Token token;     /* 次のトークンを入れておく */

static void block(int pIndex);      /* ブロックのコンパイル */
                                    /* pIndex はこのブロックの関数名のインデックス */
static void constDecl();            /* 定数宣言のコンパイル */
static void varDecl();              /* 変数宣言のコンパイル */
static void funcDecl();             /* 関数宣言のコンパイル */
static void statement();            /* 文のコンパイル */
static void expression();           /* 式のコンパイル */
static void term();                 /* 式の項のコンパイル */
static void factor();               /* 式の因子のコンパイル */
static void condition();            /* 条件式のコンパイル */
static int isStBeginKey(Token t);   /* トークンtは文の先頭のキーか？ */

