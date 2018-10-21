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

int n;
int findNumber = 0;

vvi graph;
vpi ans;

void dfs(int v) {
    if (ans[v].first == INT_MAX) ans[v].first = ++findNumber;
    
    for (int i = 0; i < n; ++i) {
        if (graph[v][i] == 1 && ans[i].first == INT_MAX) dfs(i);
    }

    if (ans[v].second == INT_MAX) ans[v].second = ++findNumber;
    return;
}

int main() {
    cin >> n;
    graph.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; ++i) {
        graph[i].resize(n);
        ans[i].first = ans[i].second = INT_MAX;
    }

    for (int i = 0; i < n; ++i) {
        int idx, cnt; cin >> idx >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int v; cin >> v;
            graph[idx-1][v-1] = 1;
        }
    }

    dfs(0);

    for (int i = 0; i < n; ++i) {
        cout << i+1 << " " << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}