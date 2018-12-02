#include <cstdio>
#include <cstdlib>
#include <string>
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
static bool printed;

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
    charClassT[':'] = colon;
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
    printed = true;
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
    printed = true;
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
    return errorNo;
}

// 次の1文字を返す関数
char nextChar() {
    char ch;
    if (lineIndex == -1) {
        if (fgets(line, MAXLINE, fpi) != NULL) {
            // 通常のエラーメッセージの出力の場合（参考まで）
            /* puts(line); */
            lineIndex = 0;
        } else {
            // end of file ならコンパイル終了
            errorF("end of file\n");
        }
    }

    if ((ch = line[lineIndex++]) == '\n') {
        // chに次の1文字
        // それが改行文字なら次の行の入力準備
        lineIndex = -1;
        // 文字としては改行文字を返す
        return '\n';
    }

    return ch;
}

// 次のトークンを読んで返す関数
Token nextToken() {
    int i = 0;
    int num;
    KeyId cc;
    Token temp;
    char ident[MAXNAME];
    // 前のトークンを印字
    printcToken();
    spaces = 0;
    CR = 0;

    while (true) {
        if (ch == ' ') {
            spaces++;
        } else if (ch == '\t') {
            // 行の先頭のタブ以外は不正確
            spaces += TAB;
        } else if (ch == '\n') {
            spaces = 0;
            CR++;
        } else {
            break;
        }
        ch = nextChar();
    }

    switch (cc = charClassT[ch]) {
    // identifier
    case letter:
        do {
            if (i < MAXNAME) {
                ident[i] = ch;
            }

            i++;
            ch = nextChar();
        } while (charClassT[ch] == letter ||
                 charClassT[ch] == digit);

        if (i >= MAXNAME) {
            errorMessage("too long");
            i = MAXNAME - 1;
        }

        ident[i] = '\0';
        for (i = 0; i < end_of_KeyWd; i++) {
            if (strcmp(ident, KeyWdT[i].word) == 0) {
                // 予約語の場合
                temp.kind = KeyWdT[i].keyId;
                cToken = temp;
                printed = false;
                return temp;
            }
        }

        // ユーザーの宣言した名前の場合
        temp.kind = Id;
        strcpy(temp.u.id, ident);
        break;

    // number
    case digit:
        num = 0;
        do {
            num = 10 * num + (ch - '0');
            i++;
            ch = nextChar();
        } while (charClassT[ch] == digit);

        if (i > MAXNUM) {
            errorMessage("too large");
        }

        temp.kind = Num;
        temp.u.value = num;
        break;

    case colon:
        if ((ch = nextChar()) == '=') {
            ch = nextChar();
            // ":="
            temp.kind = Assign;
            break;
        } else {
            temp.kind = nul;
            break;
        }

    case Lss:
        if ((ch = nextChar()) == '=') {
            ch = nextChar();
            // "<="
            temp.kind = LssEq;
            break;
        } else if (ch == '>') {
            ch = nextChar();
            // "<>"
            temp.kind = NotEq;
            break;
        } else {
            temp.kind = Lss;
            break;
        }

    case Gtr:
        if ((ch = nextChar()) == '=') {
            ch = nextChar();
            // ">="
            temp.kind = GtrEq;
            break;
        } else {
            temp.kind = Gtr;
            break;
        }

    default:
        temp.kind = cc;
        ch = nextChar();
        break;
    }

    cToken = temp;
    printed = false;
    return temp;
}

// t.kind == k のチェック
// t.kind == k なら、次のトークンを読んで返す
// t.kind != k なら、エラーメッセージを出し、
// tとkが共に記号、または予約語なら、tを捨て、次のトークンを読んで返す（tをkで置き換えたことになる）
// それ以外の場合、kを挿入したことにして、tを返す
Token checkGet(Token t, KeyId k) {
    if (t.kind == k) {
        return nextToken();
    }

    if ((isKeyWd(k) && isKeyWd(t.kind)) ||
        (isKeySym(k) && isKeySym(t.kind))) {
        errorDelete();
        errorInsert(k);
        return nextToken();
    }
    errorInsert(k);
    return t;
}

// 空白や改行の印字
static void printSpaces() {

    while (CR-- > 0) {
        fprintf(fptex, "\\ \\par\n");
    }

    while (spaces-- > 0) {
        fprintf(fptex, "\\ ");
    }

    CR = 0;
    spaces = 0;
}

// 現在のトークンの印字
void printcToken() {
    int i = (int)cToken.kind;
    if (printed) {
        printed = false;
        return;
    }

    printed = true;
    // トークンの前の空白や改行印字
    printSpaces();

    if (i < end_of_KeyWd) {
        // 予約語
        fprintf(fptex, "{\\bf %s}", KeyWdT[i].word);
        fprintf(fptex, "{\\bf %s}", KeyWdT[i].word);
    } else if (i < end_of_KeySym) {
        // 演算子か区切り記号
        fprintf(fptex, "$%s$", KeyWdT[i].word);
    } else if (i == (int)Id) {
        switch (idKind) {
        case varId:
            fprintf(fptex, "%s", cToken.u.id);
            return;
        case parId:
            fprintf(fptex, "{\\sl %s}", cToken.u.id);
            return;
        case funcId:
            fprintf(fptex, "{\\it %s}", cToken.u.id);
            return;
        case constId:
            fprintf(fptex, "{\\sf %s}", cToken.u.id);
            return;
        }
    } else if (i == (int)Num) {
        // Num
        fprintf(fptex, "%d", cToken.u.value);
    }
}

// 現トークン（Id）の種類をセット
void setIdKind(KindT k) {
    idKind = k;
}
