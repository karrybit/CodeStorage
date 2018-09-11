#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    int ac = n - m;
    int acTime = ac * 100;
    int waTime = m * 1900;

    int b = 1 << m;

    int ans = acTime * b + waTime * b;

    cout << ans << endl;

    return 0;
}