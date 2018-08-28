#include <iostream>
#include <algorithm>

using namespace std;

int weights[5] = { 3, 4, 1, 2, 3 };
int prices[5] = { 2, 3, 2, 3, 6 };
int maxw = 10;

int table[6][11];
int ans = 0;

void nonAlgorithm(int, int, int);
int recursiceNonMemo(int, int);
int memo(int, int);
void dp();

int main() {
    int mode; cin >> mode;
    cout << "" << endl;

    if (mode == 0) {
        auto start = chrono::system_clock::now();
        nonAlgorithm(0, 0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "[not algorithm]" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;

    } else if (mode == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 11; ++j) {
                table[i][j] = -1;
            }
        }

        auto start = chrono::system_clock::now();
        ans = recursiceNonMemo(0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();

        cout << "[recursive not memo]" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;

    } else if (mode == 2) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 11; ++j) {
                table[i][j] = -1;
            }
        }

        auto start = chrono::system_clock::now();
        ans = memo(0, 0);
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        
        cout << "[memo]" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;

    } else {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 11; ++j) {
                table[i][j] = 0;
            }
        }

        auto start = chrono::system_clock::now();
        dp();
        auto end = chrono::system_clock::now();

        auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
        
        cout << "[dynamic planning]" << endl;
        cout << "ans: " << ans << endl;
        cout << "time: " << msec << " ms" << endl;
    }

    return 0;
}

void nonAlgorithm(int n, int w, int p) {
    if (w > maxw) return;
    ans = max(ans, p);
    if (n >= 5) return;
    nonAlgorithm(n + 1, w, p);
    nonAlgorithm(n + 1, w + weights[n], p + prices[n]);
}

int recursiceNonMemo(int n, int w) {
    if (w > maxw) return -100;
    if (n >= 5) return 0;
    return max(recursiceNonMemo(n + 1, w), recursiceNonMemo(n + 1, w + weights[n]) + prices[n]);
}

int memo(int n, int w) {
    if (w > maxw) return -100;
    if (n >= 5) return 0;
    if (table[n][w] >= 0) return table[n][w];
    return table[n][w] = max(memo(n + 1, w), memo(n + 1, w + weights[n]) + prices[n]);
}

void dp() {
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (j + weights[i - 1] <= 10) {
                table[i][j + weights[i - 1]] = max(table[i - 1][j], table[i - 1][j] + prices[i - 1]);
                ans = max(ans, table[i][j + weights[i - 1]]);
            }
        }
    }
}
