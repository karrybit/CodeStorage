#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

int main() {
    int n; cin >> n;
    vector<pi> reds; reds.resize(n);
    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        reds[i].first = a;
        reds[i].second = b;
    }

    vector<pi> blues; blues.resize(n);
    for (int i = 0; i < n; ++i) {
        int c, d; cin >> c >> d;
        blues[i].first = c;
        blues[i].second = d;
    }


    return 0;
}
