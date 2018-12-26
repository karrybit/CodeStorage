#include <ListLexer.hpp>

bool ListLexer::isLetter() {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
