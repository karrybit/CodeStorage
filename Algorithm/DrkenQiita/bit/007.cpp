#include <iostream>

using namespace std;

/* 入力 */
int n;
int a[25]; // 余裕をもってサイズ 25 に
int K;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> K;

    // 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
    bool exist = false;
    for (int bit = 0; bit < (1<<n); ++bit) {
        int sum = 0; // 部分集合の和
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // i が S に入っているなら足す
                sum += a[i];
            }
        }

        // sum が K に一致するか
        if (sum == K) exist = true;
    }

    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}