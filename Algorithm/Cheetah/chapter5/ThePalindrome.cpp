#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, reversed;
    cin >> str;

    reverse_copy(str.begin(), str.end(), back_inserter(reversed));

    int offset = 0;
    for (int i = 0; i < str.length();) {
        if (reversed[i + offset] == '\0' ||
            str[i] == '\0') break;
        if (str[i] != reversed[i + offset]) {
            offset++;
            i = 0;
        } else {
            i++;
        }
    }
    
    cout << str.length() + offset << endl;
    return 0;
}