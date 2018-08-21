#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

vector<string> maze;
int startRow = 0;
int startCol = 0;
vector<int> moveRow;
vector<int> moveCol;

void scan();

int main() {
    scan();
    int ans = 0;
    int width = maze[0].size(),
        height = maze.size();

    int board[50][50];
    for (int i = 0; i < height; ++i) for (int j = 0; j < width; ++j) board[i][j] = -1;

    board[startRow][startCol] = 0;
    queue<int> queueX;
    queue<int> queueY;
    queueX.push(startCol);
    queueY.push(startRow);

    while (queueX.size() > 0) {
        int x = queueX.front(),
            y = queueY.front();
        queueX.pop();
        queueY.pop();

        for (int i = 0; i < moveRow.size(); ++i) {
            int nextX = x + moveCol[i],
                nextY = y + moveRow[i];

            if (0 <= nextX && nextX < width &&
                0 <= nextY && nextY < height &&
                board[nextY][nextX] == -1 &&
                maze[nextY].substr(nextX, 1) == ".") {
                    board[nextY][nextX] = board[y][x] + 1;
                    queueX.push(nextX);
                    queueY.push(nextY);
            }
        }
    }

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i].substr(j, 1) == "." && board[i][j] == -1) {
                ans = -1;
                goto END_LOOP;

            } else{
                ans = max(ans, board[i][j]);
            }
        }
    }

    END_LOOP:

    printf("%d\n", ans);

    return 0;
}

void scan() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        char str[50]; scanf("%s", str);
        maze.push_back(str);
    }

    scanf("%d", &startRow);
    scanf("%d", &startCol);

    int moveVariation; scanf("%d", &moveVariation);
    for (int i = 0; i < moveVariation; ++i) {
        int move; scanf("%d", &move);
        moveRow.push_back(move);
    }
    for (int i = 0; i < moveVariation; ++i) {
        int move; scanf("%d", &move);
        moveCol.push_back(move);
    }
}