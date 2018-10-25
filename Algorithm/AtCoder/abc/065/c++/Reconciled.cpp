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
    ll n, m; cin >> n >> m;

    if (abs(n - m) > 1) {
        cout << 0 << endl;
        return 0;
    }

    ull ans = 1;
    if (n == m) {
        for (ull i = 2; i <= n; ++i) ans = (ans * i) % BP;
        ans = (ans * ans) % BP;
        ans = (ans * 2) % BP;
        cout << ans << endl;
    } else {
        ll mini = min(n, m);
        for (ull i = 2; i <= mini; ++i) ans = (ans * i) % BP;
        ans = (ans * ans) % BP;
        ans = (ans * max(n, m)) % BP;
        cout << ans << endl;
    }

    return 0;
}