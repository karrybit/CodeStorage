#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> P;

int main() {
    int n, m; cin >> n >> m;
    vector<P> bridges;
    bridges.resize(m);
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        bridges[i] = P(l, r);
    }

    sort(bridges.begin(), bridges.end());

    int ans = 1;
    int s = bridges[0].first;
    for (int i = 0; i < m; ++i) {
        if (i + 1 == bridges[i].second && s >= bridges[i].first) {
            ++ans;
            s = bridges[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}