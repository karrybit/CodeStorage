#ifndef LISTLEXER_HPP
#define LISTLEXER_HPP
#include <string>
#include <vector>

using namespace std;

enum TokenType: int {
    EOF_,
    EOFTYPE,
    NAME,
    COMMA,
    LBRACK,
    RBRACK,
};

class Token;

class ListLexer {
    public:
        static vector<string> tokenNames;
        static string getTokenName(int);

        string input;
        int p;
        char c;

        ListLexer(string);
        Token nextToken();
        Token f_Name();
        void WS();
        void consume();
        void match(char);

    bool isLetter();
};

#endif
