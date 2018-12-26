#include <ListLexer.hpp>
#include <Token.hpp>

ListLexer::ListLexer(string input) : input_(input) {
    c_ = input[p_];
}

bool ListLexer::isLetter() {
    return (c_ >= 'a' && c_ <= 'z') || (c_ >= 'A' && c_ <= 'Z');
}

string ListLexer::getTokenName(int x) {
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

Token ListLexer::fName() {
    string str = "";
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
    ++p_;
    if (p_ >= input_.size()) c_ = eof;
    else                     c_ = input_[p_];
}

void ListLexer::match(char x) {
    if (c_ == x) consume();
    else         printf("expecting %c found %c", x, c_);
}
