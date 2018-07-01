#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;

int main() {
    string s;
    cin >> s;
    cout << s << endl;

    string line;
    getline(cin, line);
    cout << line << endl;
    return 0;
}
