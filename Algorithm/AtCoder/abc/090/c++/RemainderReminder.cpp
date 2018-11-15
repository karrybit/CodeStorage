#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>

#define BP 1000000007

using namespace std;

typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

typedef vector<pair<long, long> > vpl;
typedef vector<pair<int, int> > vpi;

typedef queue<long> ql;
typedef queue<int> qi;

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

template <class T>
void printvv(vector<T> vvc) { 
    for (auto vc: vvc) {
        for (auto e: vc) cout << e << " ";
        cout << endl;
    }
}

template <class T>
void printvp(vector<pair<T, T> > vp) {
    for (auto pT: vp) cout << pT.first << " " << pT.second << endl;
}

int main() {
    ll n, k;
    cin >> n >> k;

    if (k == 0) {
        cout << n * n << endl;
        return 0;
    }

    ll ans = 0;

    /// k以下の数字は条件を満たさないため、b = kからループを始める
    for (ll b = k; b <= n; ++b) {
        /// 商を対象に計算する
        ll c = n / b;
        /// (c - 1) - (k - 1)より、c - k;
        ans += c * (b - k);

        /// 剰余を対象に計算する
        ll m = n % b;
        ans += max(m - k + 1, 0ll);
    }

    cout << ans << endl;

    return 0;
}