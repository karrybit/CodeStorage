#include <iostream>
#include <vector>
#include <string>

using namespace std;

int h, w;
vector<string> maze;

int vy[4] = {1, 0, -1, 0};
int vx[4] = {0, 1, 0, -1};

bool dfs(int i, int j) {
    bool reachable = maze[i][j] == 'g';

    if (reachable) return true;

    maze[i][j] = '#';

    for (int k = 0; k < 4; ++k) {
        int ny = i - vy[k], nx = j + vx[k];
        if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
            if (maze[ny][nx] == '.' || maze[ny][nx] == 'g') {
                reachable = reachable || dfs(ny, nx);
            }
        }
    }

    return reachable;
}

int main() {
    cin >> h >> w;
    maze.resize(h);
    for (int i = 0; i < h; ++i) cin >> maze[i];

    bool ans = false;
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) {
        if (maze[i][j] == 's') ans = dfs(i, j);
    }

    cout << (ans ? "Yes" : "No") << endl;

    return 0;
}