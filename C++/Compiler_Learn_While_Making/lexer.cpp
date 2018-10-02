#include <cstdio>
#include <cstdlib>
#define MAXLINE 120 /* 1行の最大文字数 */

static FILE *fpi;           /* ソースファイル */
static FILE *fpo;           /* コンパイラの出力ファイル */
static char line[MAXLINE];  /* 1行分の入力バッファー */
static int lineIndex = -1;  /* 次に読む文字の位置 */

enum CharClass {
    letter,
    digit,
    other
};

CharClass charClassT(char ch) {
    if ('a' <= ch && ch <= 'Z') { return letter; }
    if ('0' <= ch && ch <= '9') { return digit; }
    return other;
}

char nextChar() {
    char ch;
    if (lineIndex == -1) {
        if (fgets(line, MAXLINE, fpi) != NULL) {
            fputs(line, fpo);
            lineIndex = 0;
        } else {
            printf("end of file/n");
            std::exit(1);   /* end of file ならコンパイル終了 */
        }
    }

    if ((ch = line[lineIndex++]) == '\n') { /* ch に次の1文字 */
        lineIndex = -1; /* それが改行文字なら次の行の入力準備 */
        return ' ';     /* 文字としては空白文字を返す */
    }

    return ch;
}

void backChar() {
    --lineIndex;
}

int main() {
    char ch;
    state1:
        ch = nextChar();
        if (charClassT(ch) == letter)
            goto state2;
        else
            printf("input invalid character.");
            exit(0);

    state2:
        ch = nextChar();
        if (charClassT(ch) == letter || charClassT(ch) == digit)
            goto state2;
        else
            goto state3;
    
    state3:

    return 0;
}

