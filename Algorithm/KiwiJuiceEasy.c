#include <stdio.h>

#define MAX 50
#define min(a, b) ((a) < (b) ? (a) : (b))

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
        int move = min(bottles[fromId[i]], capacities[toId[i]] - bottles[toId[i]]);
        bottles[fromId[i]] -= move;
        bottles[toId[i]] += move;
    }

    // standard output
    for (int i = 0; i < n; i++) {
        printf("%d ", bottles[i]);
    }
    printf("\n");

    return 0;
}
