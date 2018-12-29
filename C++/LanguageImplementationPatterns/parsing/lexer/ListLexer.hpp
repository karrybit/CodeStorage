#ifndef LISTLEXER_HPP
#define LISTLEXER_HPP
#include <string>
#include <vector>
#include "Token.hpp"

class ListLexer {
    public:
        static const char eof = EOF;
        static const int eof_type = 1;
        std::string input;
        int p;
        char c;

        static const int name = 2;
        static const int comma = 3;
        static const int lbrack = 4;
        static const int rbrack = 5;
        static const std::vector<std::string> tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

        ListLexer(std::string);
        std::string getTokenName(int);
        Token nextToken();
        Token f_Name();
        void WS();
        void consume();
        void match(char);

    bool isLetter();
};

#endif
