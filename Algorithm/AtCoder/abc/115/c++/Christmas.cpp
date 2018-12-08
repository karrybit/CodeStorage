#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>

#define MOD 1000000007

using namespace std;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

typedef pair<ll, ll> pll;
typedef pair<int, int> pi;

typedef vector<pll> vpl;
typedef vector<pi> vpi;

typedef queue<ll> ql;
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

vpl L;

inline ll rec(int i, ll x, ll p) {
    if (i == 0) return p + 1;
    if (x <= 1) return p;

    if (x == L[i].second) return L[i].first + p;

    ll y = (L[i].second + 1) / 2;
    if (x < y) return rec(i - 1, x - 1, p);

    p += L[i - 1].first + 1;
    if (x == y) return p;

    return rec(i - 1, x - y, p);
}

int main() {
    L.resize(51);
    ll n, x; cin >> n >> x;

    L[0] = pll(1, 1);

    for (int i = 1; i <= n; ++i) {
        ll p = L[i - 1].first * 2 + 1;
        ll h = L[i - 1].second * 2 + 3;
        L[i] = pll(p, h);
    }

    cout << rec(n, x, 0) << endl;

    return 0;
}