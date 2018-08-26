#include <iostream>
#include <chrono>

using namespace std;

int h, w, mode;
unsigned long long int ans = 0;
unsigned long long int dp[1000007][1000007] = {};

unsigned long long int dfs1(int, int);
unsigned long long int dfs2(int, int);
void dpCalc();

int main() {
    cin >> h >> w >> mode;

    if (mode == 0) {
        auto start = chrono::system_clock::now();
        ans = dfs1(0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "not memo" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;

    } else if (mode == 1) {
        auto start = chrono::system_clock::now();
        ans = dfs2(0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "memo" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;

    } else {
        auto start = chrono::system_clock::now();
        dpCalc();
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "dp" << endl;
        cout << "ans: " << dp[h][w] << endl;
        cout << "time: " << msec << " ms" << endl;
    }

    return 0;
}

unsigned long long int dfs1(int nowh, int noww) {
    if (nowh > h || noww > w) return 0;
    if (nowh == h && noww == w) return 1;
    return dfs1(nowh +1, noww) + dfs1(nowh, noww + 1);
}

unsigned long long int dfs2(int nowh, int noww) {
    if (nowh > h || noww > w) return 0;
    if (nowh == h && noww == w) return 1;
    if (dp[nowh][noww] != 0) return dp[nowh][noww];
    return dp[nowh][noww] = dfs2(nowh + 1, noww) + dfs2(nowh, noww + 1);
}

void dpCalc() {
    int i, j;
    dp[0][0] = 1;
    for (i = 0; i <= h; ++i) {
        for (j = 0; j <= w; ++j) {
            if (i != 0) dp[i][j] += dp[i - 1][j];
            if (j != 0) dp[i][j] += dp[i][j - 1];
        }
    }
}