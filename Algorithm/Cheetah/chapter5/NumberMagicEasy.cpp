#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string str;
    cin >> str;

    int lastIndex = str.size() - 1;
    int ans = 0;
    for (int i = lastIndex; i >= 0; --i) {
        if (str[i] == 'N') {
            ans += int(pow(2.0, lastIndex - i));
        }
    }

    cout << ++ans << endl;
    return 0;
}