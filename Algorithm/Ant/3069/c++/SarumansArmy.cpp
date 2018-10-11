#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>

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

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

int main() {
    int n, r; cin >> n >> r;
    vi vc; vc.resize(n);
    for (int i = 0; i < n; ++i) cin >> vc[i];
    sort(vc.begin(), vc.end());

    auto it = vc.begin();
    int ans = 0;
    while (it != vc.end()) {
        int temp = *it;

        while (it != vc.end() && *it <= temp + r) ++it;

        temp = *(it - 1);
        while (it != vc.end() && *it <= temp + r) ++it;

        ++ans;
    }

    cout << ans << endl;

    return 0;
}

