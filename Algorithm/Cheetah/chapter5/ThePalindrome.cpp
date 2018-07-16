#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    int lastIndex = str.length() - 1;
    int addCnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (i == lastIndex) break;
        if (str[i] != str[lastIndex - i]) addCnt++;
    }

    cout << str.length() + addCnt << endl;

    return 0;
}