#include <iostream>
#include <utility>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> P;

char maze[10][11];
int n, m;
int sx, sy;
int gx, gy;

int d[10][10];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs() {
    queue<P> que;
    // すべての点をINT_MAXで初期化
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) d[i][j] = INT_MAX;

    // スタート地点をキューに入れ、その点の距離を0にする
    que.push(P(sx, sy));
    d[sx][sy] = 0;

    // キューが空になるまでループ
    while (que.size()) {
        // キューの先頭を取り出す
        P p = que.front(); que.pop();
        // 取り出してきた状態がゴールなら探索をやめる
        if (p.first == gx && p.second == gy) break;

        // 移動4方向をループ
        for (int i = 0; i < 4; ++i) {
            // 移動した後の点を（nx, ny）とする
            int nx = p.first + dx[i], ny = p.second + dy[i];

            // 移動が可能かの判定とすでに訪れたことがあるかの判定（d[nx][ny] != MAX_INTなら訪れたことがある）
            if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && d[nx][ny] == INT_MAX) {
                // 移動できるならキューに入れ、その点の距離をpからの距離+1で確定する
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> maze[i][j];
        if (maze[i][j] == 'S') sx = i, sy = j;
        if (maze[i][j] == 'G') gx = i, gy = j;
    }

    cout << bfs() << endl;

    return 0;
}