#include <iostream>

using namespace std;

int hoge(int i, int j) { return i + j; }
int (*fuga()) (int, int) { return hoge; }

int main() {
    int (*h)(int, int);
    h = hoge;
    cout << h(10, 1) << endl;

    (int)(*)(int, int) *f;
    f = fuga;
    cout << f(10, 2) << endl;
    
    return 0;
}