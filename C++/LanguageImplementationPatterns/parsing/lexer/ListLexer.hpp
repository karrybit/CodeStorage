#import <string>

class ListLexer {
    public:
        static cosnt char eof = EOF;
        static const int eof_type = 1;
        string input;
        int p = 0;
        char c;

        static int name = 2;
        static int comma = 3;
        static int lbrack = 4;
        static int rbrack = 5;
        static string[] tokenNames = {"n/a", "<EOF>", "NAME", "COMMA", "LBRACK", "RBRACK"};

        string getTokenName(int);

        ListLexer(string input) {
            this.input = input;
            this.c = input[p];
        }

    bool isLetter();
}
