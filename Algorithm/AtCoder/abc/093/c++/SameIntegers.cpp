#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int x = max(max(a, b), c);
    int ans = 0;

    if (x * 3 % 2 != (a + b + c) % 2) ++x;

    cout << ((x * 3 - (a + b + c)) / 2) << endl;

    return 0;
}