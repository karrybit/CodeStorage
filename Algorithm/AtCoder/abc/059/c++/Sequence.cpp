#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    long long cnt, sum;

    int a = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        int peek = sum + a;

        if (sum > 0) {
            // sum is positive
            if (peek > 0) {
                // peek is positive
                
                // needs count up

            } else {
                // peek is negative
                // it meets the conditions
            }

        } else {
            // Negative
            if (peek > 0) {
                // peek is positive
                // it meets the conditions
            } else {
                // peek is negative

                // needs count up

            }
        }
        // peekの符号判定
    }

    return 0;
}