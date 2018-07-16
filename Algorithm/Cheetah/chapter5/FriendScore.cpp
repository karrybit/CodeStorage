#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int scores[50][50] = {};
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'Y') scores[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scores[i][j]) {
                for (int k = 0; k < n; k++) {
                    if (i == j) continue;
                    if (scores[i][k] || scores[j][k]) scores[i][k] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) scores[i][i] = 0;

    int maxScore = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += scores[i][j];
        }

        maxScore = max(sum, maxScore);
    }

    cout << maxScore << endl;

    return 0;
}