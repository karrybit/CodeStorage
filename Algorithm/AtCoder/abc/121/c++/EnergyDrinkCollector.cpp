#include <iostream>
#include <vector>
#include <set>
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

int main() {
    int N, M;
    cin >> N >> M;
    vpl v;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(pair<ll, ll>(a, b));
    }

    sort(v.begin(), v.end());

    ll ans = 0;
    ll now = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i].second < (M - now)) {
            ans += v[i].first * v[i].second;
            now += v[i].second;
        } else {
            ans += v[i].first * (M - now);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}