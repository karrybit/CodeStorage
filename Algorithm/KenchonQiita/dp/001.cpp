#include <iostream>
#include <algorithm>
using namespace std;

// 入力
int n;
int a[10010];  // 最大10000個ですが、少しだけ多めにとります

// DP テーブル
int dp[10010];


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[i + 1] = max(dp[i], dp[i] + a[i]);
    }

    cout << dp[n] << endl;
}