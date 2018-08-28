#include <iostream>

#define MAX 100100

using namespace std;

// 素数判定済み配列
bool prime[MAX];
// 累積和
int sum[MAX];

void calcPrime();
bool isPrime(int);

int main() {
    calcPrime();
    int q; cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        cout << (sum[r] - sum[l - 1]) << endl;
    }

    return 0;
}

void calcPrime() {
    prime[2] = true;
    sum[2] = 1;

    for (int p = 3; p < MAX; ++p) {

        // 合成数かどうか
        bool isComposite = false;

        // 判定
        for (int q = 2; q * q < p; ++q) {
            isComposite = p % q == 0;

            // 割り切れる（＝合成数）なら、素数じゃないためbreakする
            if (isComposite) break;
        }

        // 素数にtrueを立てるため、反転させる
        prime[p] = !isComposite;

        if (prime[p]) {
            // 素数 || 2017
            sum[p] = sum[p - 1] + (isPrime(p) ? 1 : 0);

        } else {
            // 合成数 && (not 2017)
            sum[p] = sum[p - 1];
        }
    }
}

bool isPrime(int i) {
    return prime[i] && prime[(i + 1) / 2];
}