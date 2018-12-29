#include <iostream>
#include "Token.hpp"
#include "ListLexer.hpp"

using namespace std;

int main() {
    ListLexer ll = ListLexer("[a, b ]");
    Token t = ll.nextToken();
    while (t.type != EOFTYPE) {
        cout << t.toString() << endl;
        t = ll.nextToken();
    }
    cout << t.toString() << endl;
    return 0;
}