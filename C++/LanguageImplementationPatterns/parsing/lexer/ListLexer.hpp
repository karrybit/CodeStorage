#include <string>

class ListLexer {
    public:
        static const char eof = EOF;
        static const int eof_type = 1;
        string input_;
        int p_ = 0;
        char c_;

        static int name = 2;
        static int comma = 3;
        static int lbrack = 4;
        static int rbrack = 5;
        static string[] tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

        string getTokenName(int);
        Token nextToken();
        Token fName();

    bool isLetter();
}
