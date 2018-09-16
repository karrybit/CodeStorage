#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<int> vc;
    vc.resize(n);

    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        --x; --y;
        vc[x] = vc[x] | 1 << y;
        vc[y] = vc[y] | 1 << x;
    }

    int ans = 0;
    for (int e: vc) ans = max(ans, int(bitset<12>(e).count()));

    cout << ans + 1 << endl;

    cout << endl;
    for (int e: vc) cout << bitset<8>(e) << endl;

    return 0;
}