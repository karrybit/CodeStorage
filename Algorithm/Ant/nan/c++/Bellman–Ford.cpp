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

// 頂点fromから頂点toへのコストcostの辺
struct edge { int from, to, cost; };

#define MAX_E 10
edge es[MAX_E];     // 辺

int d[MAX_E];       // 最短距離
int V, E;           // Vは頂点数、Eは辺数

// s番目の頂点から各頂点への最短距離を求める
void shortest_path(int s) {
    for (int i = 0; i < V; ++i) d[i] = INT_MAX;
    d[s] = 0;
    while (true) {
        bool update = false;
        for (int i = 0; i < E; ++i) {
            edge e = es[i];
            if (d[e.from] != INT_MAX && d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }

        if (!update) break;
    }
}

bool find_negative_loop() {
    memset(d, 0, sizeof(d));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < E; ++j) {
            edge e = es[j];
            if (d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;

                // n回目にも更新があるなら負の閉路が存在する
                if (i == V - 1) return true;
            }
        }
    }

    return false;
}

int main() {
    return 0;
}