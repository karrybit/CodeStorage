#include <string>
#include "Token.hpp"
#include "ListLexer.hpp"

using namespace std;

Token::Token(TokenType _type, string _text) : type(_type), text(_text) {}
string Token::toString() {
    int i = type;
    string t_name = ListLexer::tokenNames[i];
    return "<'" + text + "'," + t_name + ">";
}
