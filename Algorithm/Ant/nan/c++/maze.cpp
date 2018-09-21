#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> maze;

int vy[] = {1, 0, -1, 0};
int vx[] = {0, 1, 0, -1};

int bfs(int i, int j, int turn) {
    maze[i][j] = '#';
    ++turn;

    /// Goalの判定
    for (int k = 0; k < 4; ++k) {
        int ny = i - vy[k], nx = j + vx[k];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && maze[ny][nx] == 'G') return turn;
    }    
    
    /// 探索
    for (int k = 0; k < 4; ++k) {
        int ny = i - vy[k], nx = j + vx[k];
        if (ny >= 0 && ny < n && nx >= 0 && nx < m && maze[ny][nx] == '.') return bfs(ny, nx, turn);
    }

    return 0;
}

int main() {
    cin >> n >> m;
    maze.resize(n);
    for (int i = 0; i < n; ++i) cin >> maze[i];

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        if (maze[i][j] == 'S') cout << bfs(i, j, 0) << endl;
    }

    return 0;
}