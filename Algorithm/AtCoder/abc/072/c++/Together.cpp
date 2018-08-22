#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n; scanf("%d", &n);
    int map[100100] = {0};
    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        ++map[a];
        if (a > 0) ++map[a + 1];
        if (a < 100100) ++map[a - 1];
    }

    int ans = 0;
    for (int i = 0; i < 100100; ++i) ans = max(ans, map[i]);

    printf("%d\n", ans);

    return 0;
}