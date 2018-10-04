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
    vi a; a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    int m = a.back();

    int _min = INT_MAX;
    int idx = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (_min >= abs(m / 2 - a[i])) {
            if (idx >= 0 && a[idx] > a[i]) {
                continue;

            } else {
                _min = abs(m / 2 - a[i]);
                idx = i;
            }
        }
    }
    cout << m << " " << a[idx] << endl;


    return 0;
}
