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

int n, m;
vvi graph;

bool dfs(int from, int to) {
    if (from == to) return true;

    bool ok = false;
    for (auto v: graph[from]) {
        ok = ok || dfs(v, to);
    }

    return ok;
}


int main() {
    cin >> n >> m;

    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int from, to; cin >> from >> to;
        graph[from].push_back(to);
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int from, to; cin >> from >> to;
        cout << (dfs(from, to) ? "yes" : "no") << endl;
    }

    return 0;
}