#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vc;

int table[64];
int ans;

void dp();

int main() {

    // Input
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int d;cin >> d;
        vc.push_back(d);
    }

    /// Initialize table
    for (int i = 0; i < 64; ++i) table[i] = 0;

    ans = 0;
    dp();

    cout << ans << endl;

    return 0;
}

void dp() {

    for (int i = 0; i < n - 1; ++i) {
        table[i] = vc[i];
        if (i > 0) table[i] = max(table[i], table[i - 1]);
        if (i > 1) table[i] = max(table[i], table[i - 2] + vc[i]);
        ans = max(ans, table[i]);
    }

    for (int i = 0; i < n - 1; ++i) {
        table[i] = vc[i + 1];
        if (i > 0) table[i] = max(table[i], table[i - 1]);
        if (i > 1) table[i] = max(table[i], table[i - 2] + vc[i + 1]);
        ans = max(ans, table[i]);
    }

}