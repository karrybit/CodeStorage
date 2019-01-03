#include <vector>
#include <string>
#include "ListLexer.hpp"
#include "Token.hpp"

using namespace std;

ListLexer::ListLexer(string _input) : input(_input) {
    c = input[p];
}

bool ListLexer::isLetter() {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

Token ListLexer::nextToken() {
    while (c != EOF) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                WS();
                continue;
            case ',':
                consume();
                return *(new Token(COMMA, ","));
            case '[':
                consume();
                return *(new Token(LBRACK, "["));
            case ']':
                consume();
                return *(new Token(RBRACK, "]"));
            default:
                if (isLetter()) return f_Name();
                printf("invalid character: %c\n", c);
        }
    }
    return *(new Token(EOFTYPE, "<EOF>"));
}

Token ListLexer::f_Name() {
    string str = "";
    do {
        str += c;
        consume();
    } while (isLetter());
    return *(new Token(NAME, str));
}

void ListLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') consume();
}

void ListLexer::consume() {
    ++p;
    if (p >= input.size()) c = EOF;
    else                   c = input[p];
}

void ListLexer::match(char x) {
    if (c == x) consume();
    else        printf("expecting %c found %c", x, c);
}
