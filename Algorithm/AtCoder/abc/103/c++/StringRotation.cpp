#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    int length = str1.length();

    bool ok = false;
    for (int i = 0; i < length + 1; i++) {
        if (str1 == str2) {
            ok = true;
            break;
        } else {
            char s = *--str1.end();
            for (int j = length - 2; j >= 0; j--) str1[j + 1] = str1[j];
            str1[0] = s;
        }
    }

    if (ok) cout << "Yes" << endl;
    else    cout << "No" << endl;

    return 0;
}