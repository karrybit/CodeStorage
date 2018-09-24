#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

int main() {
    int n, m, x, y; cin >> n >> m >> x >> y;
    vector<int> xs;
    xs.resize(n);
    for (int i = 0; i < n; ++i) cin >> xs[i];
    vector<int> ys;
    ys.resize(m);
    for (int i = 0; i < m; ++i) cin >> ys[i];

    int xmax = *max_element(xs.begin(), xs.end());
    xmax = max(xmax, x);
    int ymin = *min_element(ys.begin(), ys.end());
    ymin = min(ymin, y);

    cout << (xmax < ymin ? "No War" : "War") << endl;

    return 0;
}