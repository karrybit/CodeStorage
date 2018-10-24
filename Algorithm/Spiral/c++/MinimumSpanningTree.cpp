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
    vi minCosts(n), parents(n), color(n);

    // 初期化
    for (int i = 0; i < n; ++i) {
        minCosts[i] = INT_MAX;
        parents[i] = -1;
        color[i] = WHITE;
    }

    // スタート地点なので0
    minCosts[0] = 0;

    int parent, minv;
    while (true) {
        parent = -1;
        minv = INT_MAX;

        // こっちは親の話
        for (int i = 0; i < n; ++i) {
            if (color[i] != BLACK && minCosts[i] < minv) {
                // 辺の存在が確約されている頂点に関して
                // 最小コストの頂点をparentとして探索を行うための準備
                parent = i;
                minv = minCosts[i];
            }
        }

        if (parent == -1) break;
        color[parent] = BLACK;

        for (int v = 0; v < n; ++v) {
            // 頂点vについて
            if (color[v] != BLACK && table[parent][v] != INT_MAX) {
                // 未通過 && 辺が存在し
                if (minCosts[v] > table[parent][v]) {
                    // その辺の重みが保持している辺の現状最小の重みよりも小さい場合
                    minCosts[v] = table[parent][v];
                    parents[v] = parent;
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        // -1はスタート位置
        if (parents[i] != -1) sum += table[i][parents[i]];
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