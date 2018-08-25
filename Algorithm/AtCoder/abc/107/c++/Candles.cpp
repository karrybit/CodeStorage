#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <climits>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    vector<int> vc;
    int current = 0;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        vc.push_back(x);
    }

    unsigned long cost = LONG_MAX;
    for (int l = 0; l <= n - k; ++l) {
        unsigned long lCost, rCost;
        int r = l + k - 1;
        lCost = abs(vc[l]) + abs(vc[r] - vc[l]);
        rCost = abs(vc[r]) + abs(vc[l] - vc[r]);
        cost = min(cost, min(lCost, rCost));
    }

    printf("%ld\n", cost);

    return 0;
}