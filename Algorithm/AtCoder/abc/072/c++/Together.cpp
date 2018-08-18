#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> vc;
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        vc.push_back(a);
    }

    sort(vc.begin(), vc.end());
    int median = vc[n/2];

    int cnt = 0;
    for(int e: vc) {
        if (median - 1 <= e && e <= median + 1) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}