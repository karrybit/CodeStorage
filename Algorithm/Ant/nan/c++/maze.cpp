#include <iostream>
#include <utility>
#include <climits>

using namespace std;

int n, m, sx, sy, gx, gy;
char maze[10][10];
int reach[10][10];

pair<int, int> queue[124];
int front = 0, back = 0;

void enqueue(pair<int, int> point) { queue[back++] = point; }
pair<int, int> dequeue() { return queue[front++]; }

int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs() {
    pair<int, int> start = pair<int, int>(sx, sy);
    enqueue(start);
    reach[sx][sy] = 0;

    while(front < back) {
        pair<int, int> point = dequeue();

        if (maze[point.first][point.second] == 'G') break;

        for (int i = 0; i < 4; ++i) {
            int nx = point.first + dx[i], ny = point.second + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && maze[nx][ny] != '#' && reach[nx][ny] == INT_MAX) {
                enqueue(pair<int, int>(nx, ny));
                reach[nx][ny] = reach[point.first][point.second] + 1;
            }
        }
    }

    return reach[gx][gy];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        cin >> maze[i][j];
        if (maze[i][j] == 'S') sx = i, sy = j;
        if (maze[i][j] == 'G') gx = i, gy = j;
        reach[i][j] = INT_MAX;
    }

    cout << bfs() << endl;

    return 0;
}