#include <cstdio>

using namespace std;

bool grid[100][100] = {false};
int vx[] = {1, -1, 0, 0};
int vy[] = {0, 0, 1, -1};
double prob[4];

double dfs(int x, int y, int n) {
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

double getProbability(int n, int east, int west, int south, int north) {
    prob[0] = east  / 100.0;
    prob[1] = west  / 100.0;
    prob[2] = south / 100.0;
    prob[3] = north / 100.0;

    return dfs(50, 50, n);
}

int main() {
    int n, east, west, south, north;
    scanf("%d", &n);
    scanf("%d", &east);
    scanf("%d", &west);
    scanf("%d", &south);
    scanf("%d", &north);
    double probability = getProbability(n, east, west, south, north);
    printf("%fd\n", probability);
    return 0;
}