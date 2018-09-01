#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    int a = n / 2;
    int b = n % 2 == 0 ? 0 : 1;
    cout << (a * (a + b)) << endl;
    return 0;
}