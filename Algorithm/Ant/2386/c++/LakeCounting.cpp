#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> table;

void dfs(int i, int j) {
    table[i][j] = '.';
    for (int x = -1; x <= 1; ++x) {
        for (int y = -1; y <= 1; ++y) {
            if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < m && table[i + x][j + y] == 'W') dfs(i + x, j + y);
        }
    }
}

int main() {
    cin >> n >> m;
    table.resize(n);
    for (int i = 0; i < n; ++i) cin >> table[i];

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (table[i][j] == 'W') {
                dfs(i, j);
                ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}