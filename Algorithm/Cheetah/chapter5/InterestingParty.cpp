#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> fv;
    vector<string> sv;
    string str;

    for (int i = 0; i < n; i++) {
        cin >> str;
        fv.push_back(str);
    }

    for (int i = 0; i < n; i++) {
        cin >> str;
        sv.push_back(str);
    }

    int maxTheme;
    for (int i = 0; i < n; i++) {
        int maxI;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (fv[i] == fv[j] || fv[i] == sv[j]) maxI++;
        }

        maxTheme = max(maxTheme, maxI);
    }

    cout << maxTheme << endl;

    return 0;
}
