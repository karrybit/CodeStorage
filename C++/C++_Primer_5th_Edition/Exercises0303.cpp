#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string lhs, rhs;
    cin >> lhs >> rhs;

    if (lhs > rhs)
        cout << "lhs is longer than rhs" << endl;
    else if (lhs < rhs)
        cout << "rhs is longer than lhs" << endl;
    else
        cout << "lhs is equal to rhs" << endl;

    return 0;
}
