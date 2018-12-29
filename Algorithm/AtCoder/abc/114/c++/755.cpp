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

unsigned long n;

set<int> ans;

void rec(unsigned long t) {
    if (t > n) return;
//    cout << t << endl;
    int d = log10(t) + 1;
    int p = pow(10, d);
    ans.insert(t);
    rec(p * 3 + t);
    rec(p * 5 + t);
    rec(p * 7 + t);
    rec(t * 10 + 3);
    rec(t * 10 + 5);
    rec(t * 10 + 7);
}

int main() {
    cin >> n;
    if (n < 357) {
        cout << 0 << endl;
        return 0;
    }

    rec(357);
    rec(375);
    rec(537);
    rec(573);
    rec(735);
    rec(753);

    cout << ans.size() << endl;

    return 0;
}