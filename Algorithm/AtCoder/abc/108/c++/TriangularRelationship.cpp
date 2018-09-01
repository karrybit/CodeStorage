#include <iostream>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int cnt;

    for (int a = 1; a <= n; ++a) {
        int b = a > k ? k - (a % k) : k - a;

        for (; b <= n; b += k) {
            if (b < 1) continue;
            int c = c > k ? k - (b % k) : k - b;
            
            for (; c <= n; c += k) {
                if (c < 1) continue;
                if ((a + b) % k == 0 && (b + c) % k == 0 && (c + a) % k == 0) ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}