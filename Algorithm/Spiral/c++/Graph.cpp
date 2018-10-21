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

int main() {
    int n; cin >> n;
    vvi graph; graph.resize(n);
    for (int i = 0; i < n; ++i) graph[i].resize(n);

    for (int i = 0; i < n; ++i) {
        int j, c; cin >> j >> c;
        for (int k = 0; k < c; ++k) {
            int l; cin >> l;
            graph[i][l - 1] = 1;
        }
    }

    printvv(graph);

    return 0;
}