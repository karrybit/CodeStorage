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
    // ("n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK")
        static const vector<string> tokenNames;

        string input;
        int p;
        char c;

        ListLexer(string);
        string getTokenName(int);
        Token nextToken();
        Token f_Name();
        void WS();
        void consume();
        void match(char);

    bool isLetter();
};

#endif
