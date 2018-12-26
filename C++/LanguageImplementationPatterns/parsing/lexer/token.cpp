#include <Token.hpp>

Token::Token(int type, string text) : type_(type), text_(text) {}
string Token::toString() {
    string t_name = ListLexer.tokenNames[this->type];
    return "<'" + this->text + "'," + t_name + ">";
}
