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

vvi table;
int n;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int prim() {
    int u, minv;
    vi d(n), p(n), color(n);

    for (int i = 0; i < n; ++i) {
        d[i] = INT_MAX;
        p[i] = INT_MAX;
        color[i] = WHITE;
    }

    d[0] = 0;

    while (true) {
        minv = INT_MAX;
        u = -1;
        for (int i = 0; i < n; ++i) {
            if (minv > d[i] && color[i] != BLACK) {
                u = i;
                minv = d[i];
            }
        }

        if (u == -1) break;
        color[u] = BLACK;
        for (int v = 0; v < n; ++v) {
            if (color[v] != BLACK && table[u][v] != INT_MAX) {
                if (d[v] > table[u][v]) {
                    d[v] = table[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] != -1) sum += table[i][p[i]];
    }

    return sum;
}

int main() {
    cin >> n;
    table.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int cost; cin >> cost;
            cost = cost < 0 ? INT_MAX : cost;
            table[i].push_back(cost);
        }
    }

    cout << prim() << endl;

    return 0;
}