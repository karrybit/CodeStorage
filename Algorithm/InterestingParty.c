#include <stdio.h>

#define MAX 50
#define LEN 15

int n;
char firsts[MAX][LEN];
char seconds[MAX][LEN];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", firsts[i]);
    for (int i = 0; i < n; i++) scanf("%s", seconds[i]);
    return 0;
}
