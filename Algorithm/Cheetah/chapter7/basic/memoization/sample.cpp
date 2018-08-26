#include <iostream>
#include <chrono>

using namespace std;

int h, w, mode;
unsigned long long int ans = 0;
int dp[1000007][1000007] = {};

unsigned long long int dfs1(int, int);
unsigned long long int dfs2(int, int);

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

    } else {
        auto start = chrono::system_clock::now();
        ans = dfs2(0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "memo" << endl;
        cout << "ans: " << ans << endl;
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