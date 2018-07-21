#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2) cout << "Yes" << endl;
    else              cout << "No" << endl;

    return 0;
}