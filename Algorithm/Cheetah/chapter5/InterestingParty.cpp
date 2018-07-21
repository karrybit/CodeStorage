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

    int maxTheme = 0;
    for (int i = 0; i < n; i++) {
        int maxF = 0;
        int maxS = 0;
        for (int j = 0; j < n; j++) {
            if (fv[i] == fv[j] || fv[i] == sv[j]) maxF++;
            if (sv[i] == fv[j] || sv[i] == sv[j]) maxS++;
        }

        maxTheme = max(maxTheme, max(maxF, maxS));
    }

    cout << maxTheme << endl;

    return 0;
}
