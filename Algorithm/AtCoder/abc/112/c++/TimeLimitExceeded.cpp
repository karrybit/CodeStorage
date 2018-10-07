#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

int dp[100][100];

int main() {
    int n, T; cin >> n >> T;
    vector<pi> vpi;
    vpi.resize(n);

    for (int i = 0; i < n; ++i) {
        int c, t; cin >> c >> t;
        vpi[i] = pi(c, t);
    }

    sort(vpi.begin(), vpi.end());

    int cost = 0;

    int mini = INT_MAX;

    for (int i = 0; i < n; ++i) {
        if (vpi[i].second <= T) {
            mini = min(mini, vpi[i].first);
        }
    }

    if (mini == INT_MAX) {
        cout << "TLE" << endl;
    } else {
        cout << mini << endl;
    }

    return 0;
}
