#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>

using namespace std;

class ListLexer;

class Token {
    public:
        TokenType type;
        string text;
        string toString();
        Token(TokenType, string);
};

#endif
