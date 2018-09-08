#include <iostream>

using namespace std;

int main() {
    int a = 45; // 実際上は 0b101101、あるいは 0x2d と書く
    int b = 25;
    cout << a << " OR " << b << " = " << (a|b) << endl;
}