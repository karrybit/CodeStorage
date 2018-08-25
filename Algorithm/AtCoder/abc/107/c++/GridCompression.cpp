#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int h, w;
vector<string> grid;

void checkAndErase() {
    for (int i = h - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == '#') {
                flag = false;
                break;
            }
        }

        if (flag) {
            grid.erase(grid.begin() + i);
        }
    }

    h = grid.size();
    if (h == 0) return; 

    w = grid[0].size();

    for (int i = w - 1; i >= 0; --i) {
        bool flag = true;
        for (int j = 0; j < h; ++j) {
            if (grid[j][i] == '#') {
                flag = false;
                break;
            }
        }

        if (flag) {
            for (int j = 0; j < h; ++j) {
                auto idx = grid[j].begin() + i;
                grid[j].erase(idx, idx + 1);
            }
        }
    }
}

void print() {
    for (auto e: grid) {
        cout << e << endl;
    }
}

int main() {
    scanf("%d %d", &h, &w);
    for (int i = 0; i < h; ++i) {
        string str; cin >> str;
        grid.push_back(str);
    }

    checkAndErase();
    print();

    return 0;
}