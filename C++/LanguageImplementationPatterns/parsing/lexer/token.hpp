#ifdef TOKEN_HPP
#define TOKEN_HPP
#include <string>

class Token {
    public:
        int type_;
        std::string text_;
        std::string toString();
        Token(int, std::string);
}

#endif
