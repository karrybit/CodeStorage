#include <stdio.h>
#include <string.h>

#define MAX 50
#define LEN 15
#define max(a, b) ((a) > (b) ? (a) : (b))

int n;
char firsts[MAX][LEN];
char seconds[MAX][LEN];
int match[MAX];

int main() {
    // standard input
    scanf("%d", &n);

    // initialize
    for (int i = 0; i < n; i++) scanf("%s", firsts[i]);
    for (int i = 0; i < n; i++) scanf("%s", seconds[i]);
    for (int i = 0; i < MAX; i++) match[i] = 1;

    for (int i = 0; i < n; i++) for (int j = i; j < n; j++) {
        if (i == j) continue;

        // 1つでも一致すれば足す
        if (!(strcmp(firsts[i], firsts[j]) &&
            strcmp(firsts[i], seconds[j]) &&
            strcmp(seconds[i], firsts[j]) &&
            strcmp(seconds[i], seconds[j]))) {
            match[i]++; match[j]++;
        }
    }

    // return value
    int participant = 1;
    for (int i = 0; i < n; i++) {
        participant = max(participant, match[i]);
    }

    // standard output
    printf("%d\n", participant);

    return 0;
}
