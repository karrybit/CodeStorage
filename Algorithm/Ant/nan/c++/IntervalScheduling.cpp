#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<unsigned int, unsigned int> P;

int main() {
    int n; cin >> n;
    vector<P> tasks;
    tasks.resize(n);
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        tasks[i] = P(l, r);
    }

    sort(tasks.begin(), tasks.end());

    int ans = 0, t = 0;
    for (int i = 0; i < n; ++i) {
        if (t < tasks[i].first) {
            ++ans;
            t = tasks[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}