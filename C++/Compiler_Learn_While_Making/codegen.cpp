#include <cstdio>
#include "codegen.h"
#ifndef TBL
#define TBL
#include "table.h"
#endif
#include "getSource.h"

// 目的コードの最大長さ
#define MAXCODE 200
// 実行時スタックの最大長さ
#define MAXMEM 2000
// 演算レジスタスタックの最大長さ
#define MAXREG 20
// ブロックの最大深さ
#define MAXLEVEL 5

// 命令語の型
typedef struct inst {
    OpCode opCode;
    union {
        RelAddr addr;
        int value;
        Operator optr;
    } u;
} Inst;

// 目的コードが入る
static Inst code[MAXCODE];
// 最後に生成した命令語のインデックス
static int cIndex = -1;
// 目的コードのインデックスの増加とチェック
static void checkMax();
// 命令語の印字
static void printCode(int i);

// 次の命令語のアドレスを返す
int nextCode() {
    return cIndex + 1;
}

// 命令語の生成、アドレス部にv
int genCodeV(OpCode op, int v) {
    checkMax();
    code[cIndex].opCode = op;
    code[cIndex].u.value = v;
    return cIndex;
}

// 命令語の生成、アドレスは名前表から
int genCodeT(OpCode op, int ti) {
    checkMax();
    code[cIndex].opCode = op;
    code[cIndex].u.addr = relAddr(ti);
    return cIndex;
}

// 命令語の生成、アドレス部に演算命令
int genCodeO(Operator p) {
    checkMax();
    code[cIndex].opCode = opr;
    code[cIndex].u.optr = p;
    return cIndex;
}

// ret命令語の生成
int genCodeR() {
    if (code[cIndex].opCode == ret) {
        // 直前がretなら生成せず
        return cIndex;
    }
    checkMax();
    code[cIndex].opCode = ret;
    code[cIndex].u.addr.level = bLevel();
    // パラメタ数（実行スタックの解放用）
    code[cIndex].u.addr.addr = fPars();
    return cIndex;
}

// 目的コードのインデックスの増加とチェック
void checkMax() {
    if (++cIndex < MAXCODE) {
        return;
    }
    errorF("too many code");
}

// 命令語のバックパッチ（次の番地を）
void backPatch(int i) {
    code[i].u.value = cIndex + 1;
}

// 命令語のリスティング
void listCode() {
    int i;
    printf("\ncode\n");
    for (i = 0; i <= cIndex; i++) {
        printf("%3d: ", i);
        printCode(i);
    }
}
