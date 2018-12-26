#include <string>
#include "Token.hpp"
#include "ListLexer.hpp"

Token::Token(int type, std::string text) : type_(type), text_(text) {}
std::string Token::toString() {
    std::string t_name = ListLexer.tokenNames[this->type];
    return "<'" + this->text + "'," + t_name + ">";
}
