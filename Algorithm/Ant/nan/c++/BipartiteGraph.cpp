#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>

#define P 1000000007

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

// 入力
vvi G;         // グラフ
int V;              // 頂点数

vi color;    // 頂点iの色（1 or -1）

bool dfs(int v, int c) {
    // 頂点vをcで塗る
    color[v] = c;

    for (int i = 0; i < G[v].size(); ++i) {
        // 隣接している頂点が同じ色ならfalse
        if (color[G[v][i]] == c) return false;
        // 隣接している頂点がまだ塗られていないなら-cで塗る
        if (color[G[v][i]] == 0 && !dfs(G[v][i], -c)) return false;
    }

    // すべての頂点を塗られたらtrue
    return true;
}

void solve() {
    for (int i = 0; i < V; ++i) {
        if (color[i] == 0) {
            // まだ頂点iが塗られていなければ1で塗る
            if (!dfs(i, 1)) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin >> V;
    G.resize(V);
    color.resize(V);
    for (int i = 0; i < V; ++i) G[i].resize(V);
    for (int i = 0; i < V; ++i) {
        int e1, e2; cin >> e1 >> e2;
        G[e1][e2] = G[e2][e1] = 1;
    }

    // printvv(G);

    solve();

    return 0;
}