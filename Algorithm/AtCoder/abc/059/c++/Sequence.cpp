#include <iostream>
#include <complex>

using namespace std;

int main() {
    int n; cin >> n;

    int a; cin >> a;
    long long sum = a;
    long long cnt = 0;

    for (int i = 1; i < n; ++i) {
        cin >> a;
        int next = sum + a;
        int c, diff;
        c = diff = 0;

        if (sum > 0) {
            if (next > 0) {
                diff = (-1 - sum);
                a = diff - a;
                c = diff;
            }

        } else {
            if (next <= 0) {
                diff = (1 - sum) - a;
                a += diff;
                c = diff;
            }
        }

        sum += a;
        cnt += abs(c);
    }

    cout << cnt << endl;

    return 0;
}