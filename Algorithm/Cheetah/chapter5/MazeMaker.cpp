#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int board[50][50] = {1};
vector<string> maze;
int startRow = 0;
int startCol = 0;
vector<int> moveRow;
vector<int> moveCol;

void scan();

int main() {
    scan();
    return 0;
}

void scan() {
    int x; scanf("%d", &x);
    for (int i = 0; i < x; ++i) {
        char str[50]; scanf("%s", str);
        maze.push_back(str);
    }

    for (string str: maze) {
        printf("%s\n", str.c_str());
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