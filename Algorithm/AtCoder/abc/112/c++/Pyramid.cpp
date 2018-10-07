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
    vi x(n, 0), y(n, 0), h(n, 0);
    for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> h[i];

    bool ok = false;
    for (int cx = 0; cx <= 100; ++cx ) {
        for (int cy = 0; cy<= 100; ++cy) {
            bool ok = true;
            int height = -1;
            for (int i = 0; i < n; ++i) {
                if (h[i] > 0) {
                    int temp = h[i] + abs(cx - x[i]) + abs(cy - y[i]);
                    if (height == -1) {
                        height = temp;
                    } else {
                        if (height != temp) {
                            ok = false;
                            break;
                        }
                    }
                }
            }

            if (!ok) continue;
            
            for (int i = 0; i < n; ++i) {
                if (h[i] == 0) {
                    int temp = abs(cx - x[i]) + abs(cy - y[i]);
                    if (height > temp) {
                        ok = false;
                        break;
                    }
                }
            }

            if (!ok) continue;

            cout << cx << " " << cy << " " << height << endl;
            return 0;
        }
    }

    return 0;
}
