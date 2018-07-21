#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    auto eItr = --str.end();
    int addCnt = 0;
    for (char s: str) {
        if (s == *eItr) --eItr;
        else            ++addCnt;
    }

    cout << str.length() + addCnt << endl;

    return 0;
}