#include <iostream>
#include <string>

using namespace std;

int main() {
    string str; cin >> str;

    int bit = 0;
    for (; bit < 16; ++bit) {
        int sum = str[0] - '0';
        for (int j = 1; j < 4; ++j) {
            if (bit & 1 << (3 - j)) sum += str[j] - '0';
            else                    sum -= str[j] - '0';
        }

        if (sum == 7) break;
    }

    cout << str[0];
    for (int i = 1; i < 4; ++i) {
        if (bit & 1 << (3 - i)) cout << '+';
        else                    cout << '-';
        cout << str[i];
    }

    cout << "=7" << endl;

    return 0;
}