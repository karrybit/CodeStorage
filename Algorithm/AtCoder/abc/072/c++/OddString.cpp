#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;
    int len = str.length();
    string ret = "";
    for (int i = 0; i < len; i++) {
        if (i % 2 == 0 || i == 0) {
            ret += str[i];
        }
    }

    cout << ret << endl;
    return 0;
}