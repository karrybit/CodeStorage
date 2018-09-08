#include <iostream>
#include <vector>
#include <string>

using namespace std;

int table[512][512];

int vy[] = {0, -1};
int vx[] = {1, 0};

int main() {
    int h, w; cin >> h >> w;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int a; cin >> a;
            table[i][j] = a;
        }
    }

    vector<string> vc;

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (table[i][j] % 2 == 0) continue;
            for (int k = 0; k < 2; ++k) {
                if (i - vy[k] < 0 || i - vy[k] >= h) continue;
                if (j + vx[k] < 0 || j + vx[k] >= w) continue;
                ++table[i - vy[k]][j + vx[k]];
                --table[i][j];
                string str = to_string(i+1) + " " + to_string(j+1) + " " + to_string(i - vy[k] + 1) + " " + to_string(j + vx[k] + 1);
                vc.push_back(str);
                break;
            }
        }
    }

    cout << vc.size() << endl;
    for (string str: vc) cout << str << endl;

    return 0;
}