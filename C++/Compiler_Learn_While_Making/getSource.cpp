#include <stdio.h>
#include <string.h>
#include "getSource.h"

// 1行の最大文字数
#define MAXLINE 120
// これ以上のエラーがあったら終わり
#define MAXERROR 30
// 定数の最大桁数
#define MAXNUM 14

// タブのスペース
#define TAB 5

// ソースファイル
static FILE *fpi;
// LaTeX出力ファイル
static FILE *fptex;
// 1行分の入力バッファ
static char line[MAXLINE];
// 次に読む文字の位置
static int lineIndex;
// 最後に読んだ文字
static char ch;

// 最後に読んだトークン
static Token cToken;
// 現トークン（Id）の種類
static KindT idKind;
// そのトークンの前のスペースの個数
static int spaces;
// その前のCRの個数
static int CR;
// トークンは印字済みか
static int printed;

// 出力したエラーの数
static int errorNo = 0;
// 次の文字を読む関数
static char nextChar();
// tは記号か？
static int isKeySym(KeyId k);
// tは予約後か？
static int isKeyWd(KeyId k);
// トークンの前のスペースの印字
static void printSpaces();
// トークンの印字
static void printcToken();

struct keyWd {
    char *word;
    KeyId keyId;
};

static struct keyWd KeyWdT[] = {
    // 予約語の表
    { "begin", Begin },
    { "end", End },
    { "if", If },
    { "then", Then },
    { "while", While },
    { "do", Do },
    { "return", Ret },
    { "function", Func },
    { "var", Var },
    { "const", Const },
    { "odd", Odd },
    { "write", Write },
    { "writeln", WriteLn },
    { "$dummy1", end_of_KeyWd },

    // 記号と名前（KeyId）の表
    { "+", Plus },
    { "-", Minus },
    { "*", Mult },
    { "/", Div },
    { "(", Lparen },
    { ")", Rparen },
    { "=", Equal },
    { "<", Lss },
    { ">", Gtr },
    { "<>", NotEq },
    { "<=", LssEq },
    { ">=", GtrEq },
    { ",", Comma },
    { ".", Period },
    { ";", Semicolon },
    { ":=", Assign },
    { "$dummy2", end_of_KeySym }
};

// キーkは予約語か？
int isKeyWd(KeyId k) {
    return (k < end_of_KeyWd);
}

// キーkは記号か？
int isKeySym(KeyId k) {
    if (k < end_of_KeyWd) {
        return 0;
    }

    return (k < end_of_KeySym);
}

// 文字の種類を示す表にする
static KeyId charClassT[256];

// 文字の種類を示す表を作る関数
static void initCharClassT() {
    int i;
    for (i = 0; i < 256; i++) {
        charClassT[i] = others;
    }
    for (i = '0'; i <= '9'; i++) {
        charClassT[i] = digit;
    }
    for (i = 'A'; i <= 'Z'; i++) {
        charClassT[i] = letter;
    }
    for (i = 'a'; i <= 'z'; i++) {
        charClassT[i] = letter;
    }

    charClassT['+'] = Plus;
    charClassT['-'] = Minus;
    charClassT['*'] = Mult;
    charClassT['/'] = Div;
    charClassT['('] = Lparen;
    charClassT[')'] = Rparen;
    charClassT['='] = Equal;
    charClassT['<'] = Lss;
    charClassT['>'] = Gtr;
    charClassT[','] = Comma;
    charClassT['.'] = Period;
    charClassT[';'] = Semicolon;
    charClassT[':'] = Colon;
}

// ソースファイルのopen
int openSource(char fileName[]) {
    char fileNameO[30];
    if ((fpi = fopen(fileName, "r")) == NULL) {
        printf("can't open %s\n", fileName);
        return 0;
    }
    strcpy(fileNameO, fileName);
    strcat(fileNameO, ".tex");
    if ((fptex = fopen(fileNameO, "w")) == NULL) {
        printf("can't open %s\n", fileNameO);
        return 0;
    }
    return 1;
}

// ソースファイルと.texファイルをclose
void closeSource() {
    fclose(fpi);
    fclose(fptex);
}

void initSource() {
    lineIndex = -1;
    ch = '\n';
    printed = 1;
    initCharClassT();

    // LaTeXコマンド
    fprintf(fptex, "\\documentstyle[12pt]{article}\n");
    fprintf(fptex, "\\begin{document}\n");
    fprintf(fptex, "\\fboxsep=0pt\n");
    fprintf(fptex, "\\def\\insert#1{$\\fbox{#1}$}\n");
    fprintf(fptex, "\\def\\delete#1{$\\fboxrule=.5mm\\fbox{#1}$}\n");
    fprintf(fptex, "\\rm\n");
}

void finalSource() {
    if (cToken.kind == Period) {
        printcToken();
    } else {
        errorInsert(Period);
    }
    fprintf(fptex, "\n\\end{document}\n");
}

// 通常のエラーメッセージの出力の仕方（参考まで）
void error(char *m) {
    if (lineIndex > 0) {
        printf("%*s\n", lineIndex, "***^");
    } else {
        printf("^\n");
    }

    printf("*** error *** %s\n", m);
    errorNo++;
    if (errorNo > MAXERROR) {
        printf("too many errors\n");
        printf("abort compilation\n");
        exit(1);
    }
}

// エラーの個数のカウント、多すぎたら終わり
void errorNoCheck() {
    if (errorNo++ > MAXERROR) {
        fprintf(fptex, "too many errors\n\\end{document}\n");
        printf("abort compilation\n");
        exit (1);
    }
}

// 型エラーを.texファイルに出力
void errorType(char *m) {
    printSpaces();
    fprintf(fptex, "\\(\\stackrel{\\mbox{\\scriptsize %s}}{\\mbox{", m);
    printcToken();
    fprintf(fptex, "}}\\)");
    errorNoCheck();
}

// keyString(k)を.texファイルに挿入
void errorInsert(KeyId k) {
    if (k < end_of_KeyWd) {
        // 予約語
        fprintf(fptex, "\\ \\insert{{\\bf %s}}", KeyWdT[k].word);
    } else {
        // 演算子か区切り記号
        fprintf(fptex, "\\ \\insert{$%s$}", KeyWdT[k].word);
    }
    errorNoCheck();
}

// 名前がないとのメッセージを.texファイルに挿入
void errorMissingId() {
    fprintf(fptex, "\\insert{Id}");
    errorNoCheck();
}

// 演算子がないとのメッセージを.texファイルに挿入
void errorMissingOp() {
    fprintf(fptex, "\\insert{$\\otimes$}");
    errorNoCheck();
}

// 今読んだトークンを読み捨てる
void errorDelete() {
    int i = (int)cToken.kind;
    printSpaces();
    printed = 1;
    if (i < end_of_KeyWd) {
        // 予約語
        fprintf(fptex, "\\delete{{\\bf %s}}", KeyWdT[i].word);
    } else if (i < end_of_KeySym) {
        // 演算子か区切り記号
        fprintf(fptex, "\\delete{$%s$}", KeyWdT[i].word);
    } else if (i == (int)Id) {
        fprintf(fptex, "\\delete{%s}", cToken.u.id);
    } else if (i == (int)Num) {
        fprintf(fptex, "\\delete{%d}", cToken.u.value);
    }
}

// エラーメッセージを.texファイルに出力
void errorMessage(char *m) {
    fprintf(fptex, "$^{%s}$", m);
    errorNoCheck();
}

// エラーメッセージを出力し、コンパイルを終了
void errorF(char *m) {
    errorMessage(m);
    fprintf(fptex, "fatal errors\n\\end{document}\n");
    if (errorNo) {
        printf("total %d errors\n", errorNo);
    }
    printf("abort compilation\n");
    exit (1);
}

// エラーの個数を返す
int errorN() {
    return errorNo();
}
