#include <iostream>

#define MAX 100100

using namespace std;

// 素数判定済み配列
bool primeTable[MAX] = {false};
// 累積和
int cumulativeTable[MAX] = {0};
// クエリ
int query[MAX][2];

void calcPrime();
bool isPrime(int);

int main() {
    int q; cin >> q;

    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        query[i][0] = l;
        query[i][1] = r;
    }

    calcPrime();

    for (int i = 0; i < q; ++i) {
        cout << (cumulativeTable[query[i][1]] - cumulativeTable[query[i][0] - 1]) << endl;
    }

    cout << "" << endl;
    for (int i = 0; i < 100; ++i) {
        cout << cumulativeTable[i] << endl;
    }

    return 0;
}

void calcPrime() {
    primeTable[2] = true;
    cumulativeTable[2] = 1;

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
        primeTable[p] = !isComposite;

        if (primeTable[p] || p == 2017) {
            // 素数 || 2017
            cumulativeTable[p] = cumulativeTable[p - 1] + isPrime(p);

        } else {
            // 合成数 && (not 2017)
            cumulativeTable[p] = cumulativeTable[p - 1];
        }

        cumulativeTable[p + 1] = cumulativeTable[p];
    }
}

bool isPrime(int i) {
    return (primeTable[i] && primeTable[(i + 1) / 2]) || i == 2017;
}