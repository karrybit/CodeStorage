#include <string>

class Token {
    public:
        int type;
        string text;
        string toString();
        Token(int type, string text) {
            this->type = type;
            text->text = text;
        }
}
