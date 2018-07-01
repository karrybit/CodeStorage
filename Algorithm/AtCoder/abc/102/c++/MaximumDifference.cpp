#include <cstdio>
#include <climits>

using std::scanf;
using std::printf;

int main() {
    int n, v;
    scanf("%d", &n);
    unsigned long min = ULONG_MAX, max = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v);
        if (v < min) min = v;
        if (v > max) max = v;
    }

    printf("%lu\n", max - min);
    return 0;
}
