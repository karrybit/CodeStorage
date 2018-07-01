#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n, v;
    int min = 1, max = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v;
        if (v < min) min = v;
        if (v > max) max = v;
    }
    cout << max - min << endl;
    return 0;
}
