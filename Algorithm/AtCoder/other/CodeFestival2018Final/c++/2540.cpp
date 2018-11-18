#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>
#include <map>

#define BP 1000000007

using namespace std;

typedef long long ll;

typedef vector<ll> vll;
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

int main() {
    int n, m;
    cin >> n >> m;

    vector<vpi> table(n);
    for (int i = 0; i < m; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        table[a-1].push_back(pi(b-1, l));
        table[b-1].push_back(pi(a-1, l));
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        map<int, int> cnt;
        for (auto p: table[i]) {
            ans += cnt[2540 - p.second];
            cnt[p.second]++;
        }
    }

    cout << ans << endl;

    return 0;
}