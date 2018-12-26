#include <string>
#include "Token.hpp"
#include "ListLexer.hpp"

Token::Token(int _type, std::string _text) : type(_type), text(_text) {}
std::string Token::toString() {
    std::string t_name = ListLexer.tokenNames[type];
    return "<'" + text + "'," + t_name + ">";
}
