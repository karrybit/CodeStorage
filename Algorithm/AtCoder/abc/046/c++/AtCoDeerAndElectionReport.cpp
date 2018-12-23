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

ll gcd(ll a, ll b) {
    ll _max = max(a, b);
    ll _min = min(a, b);
    ll mod = _max % _min;
    return mod ? gcd(_min, _max % _min) : _min;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int main() {
    int n; cin >> n;

    vi T(n), A(n);
    for (int i = 0; i < n; ++i) cin >> T[i] >> A[i];

    ll t, a;
    t = a = 1;
    for (int i = 0; i < n; ++i) {
        if (t == T[i] && a == A[i]) continue;

        if (t <= T[i] && a <= A[i]) {
            t = T[i];
            a = A[i];

        } else {
            int _n = max(t / T[i], a / A[i]);
            cout << _n << endl;
            t = n * T[i];
            a = n * A[i];
        }
    }

    cout << t + a << endl;

    return 0;
}