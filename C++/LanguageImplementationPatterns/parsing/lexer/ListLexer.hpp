#ifdef LISTLEXER_HPP
#define LISTLEXER_HPP
#include <string>
#include "Token.hpp"

class ListLexer {
    public:
        static const char eof = EOF;
        static const int eof_type = 1;
        std::string input_;
        int p_ = 0;
        char c_;

        static int name = 2;
        static int comma = 3;
        static int lbrack = 4;
        static int rbrack = 5;
        static std::string[] tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

        stsd::string getTokenName(int);
        Token nextToken();
        Token fName();
        void WS();
        void consume();
        void match(char);

    bool isLetter();
}

#endif
