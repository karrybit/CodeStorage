#include <string>
#include "ListLexer.hpp"
#include "Token.hpp"

ListLexer::ListLexer(std::string _input) : input(_input) {
    c = input[p];
}

bool ListLexer::isLetter() {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

std::string ListLexer::getTokenName(int x) {
    return tokenNames[x];
}

Token ListLexer::nextToken() {
    while (c != eof) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                WS();
                continue;
            case ',':
                consume();
                return new Token(comma, ",");
            case '[':
                consume();
                return new Token(lbrack, "[");
            case ']':
                consume();
                return new Token(rbrack, "]");
            default:
                if (isLetter()) return fName();
                printf("invalid character: %c\n", c);
        }
    }
    return new Token(eof_type, "<EOF>");
}

Token ListLexer::f_Name() {
    std::string str = "";
    do {
        str += c;
        consume();
    } while (isLetter());
    return new Token(name, str);
}

void ListLexer::WS() {
    while (c == ' ' || c == '\t' || c == '\n' || c == '\r') consume();
}

void ListLexer::consume() {
    ++p;
    if (p >= input.size()) c = eof;
    else                     c = input[p];
}

void ListLexer::match(char x) {
    if (c == x) consume();
    else        printf("expecting %c found %c", x, c);
}
