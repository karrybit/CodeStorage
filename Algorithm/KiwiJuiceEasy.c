#include <stdio.h>

#define MAX 50

int capacities[MAX];
int bottles[MAX];
// fromId と toId は、とりあえず50にしておく.
int fromId[MAX];
int toId[MAX];

int main() {
    int n, m;
    scanf("%d", &n); scanf("%d", &m);

    // standard input
    for (int i = 0; i < n; i++) scanf("%d", &capacities[i]);
    for (int i = 0; i < n; i++) scanf("%d", &bottles[i]);
    for (int i = 0; i < m; i++) scanf("%d", &fromId[i]);
    for (int i = 0; i < m; i++) scanf("%d", &toId[i]);

    // move juice
    for (int i = 0; i < m; i++) {
        // 移動先の空き容量を算出
        int emptySize = capacities[toId[i]] - bottles[toId[i]];

        if (bottles[fromId[i]] > emptySize) {
            // 移動量が空き容量よりも多い場合
            bottles[fromId[i]] -= emptySize;
            bottles[toId[i]] = capacities[toId[i]];

        } else {
            // 移動量が空き容量以下の場合
            bottles[toId[i]] += bottles[fromId[i]];
            bottles[fromId[i]] = 0;
        }
    }

    // standard output
    for (int i = 0; i < n; i++) {
        printf("%d ", bottles[i]);
    }
    printf("\n");

    return 0;
}
