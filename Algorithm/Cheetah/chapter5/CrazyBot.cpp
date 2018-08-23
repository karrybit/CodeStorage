#include <cstdio>

using namespace std;

// 移動量
int move;
// 座標平面
bool grid[100][100] = {false};
// 東西南北の移動量
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, -1, 1};
// 東西南北への移動の確率
double prob[4];

void scan();
// X座標, Y座標, 残移動回数
double dfs(int, int, int);

int main() {
    scan();
    double ans = dfs(50, 50, move);
    printf("%f\n", ans);
    return 0;
}

void scan() {
    scanf("%d", &move);
    for (int i = 0; i < 4; ++i) {
        int a; scanf("%d", &a);
        prob[i] = a / 100.0;
    }
}

double dfs(int x, int y, int n) {
    // 終了条件を設定
    if (grid[x][y]) return 0;
    if (n == 0) return 1;

    grid[x][y] = true;
    double ret = 0;
    for (int i = 0; i < 4; ++i) {
        ret += dfs(x + vx[i], y + vy[i], n - 1) * prob[i];
    }

    grid[x][y] = false;

    return ret;
}