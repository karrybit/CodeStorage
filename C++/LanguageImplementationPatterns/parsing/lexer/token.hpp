#ifndef TOKEN_HPP
#define TOKEN_HPP
#include <string>

class Token {
    public:
        int type;
        std::string text;
        std::string toString();
        Token(int, std::string);
};

#endif
