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
    vi vc1; vc1.resize(n);
    for (int i = 0; i < n; ++i) cin >> vc1[i];

    vi vc2 = vc1;
    sort(vc2.begin(), vc2.end());
    int mid = n / 2;

    for (int i = 0; i < n; ++i) {
        if (vc1[i] < vc2[mid]) cout << vc2[mid];
        else                   cout << vc2[mid - 1];
        cout << endl;;
    }

    return 0;
}
