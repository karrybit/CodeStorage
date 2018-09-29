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

int main() {
    int n; cin >> n;
    vi v(100100, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];

    vector<pi> vl(100100, pi(0, 0));
    vector<pi> vr(100100, pi(0, 0));
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            ++vl[v[i]].first;
            vl[v[i]].second = v[i];
        } else{
            ++vr[v[i]].first;
            vr[v[i]].second = v[i];
        }            
    }

    sort(vl.begin(), vl.end(), greater<pi>());
    sort(vr.begin(), vr.end(), greater<pi>());

    int ans;
    if (vl[0].second != vr[0].second) ans = n - (vl[0].first + vr[0].first);
    else                              ans = n - (max(vl[0].first + vr[1].first, vl[1].first + vr[0].first));

    cout << ans << endl;

    return 0;
}
