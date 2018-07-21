#include <iostream>
#include <algorithm>

int main() {
    // standard input
    int n; scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) scanf("%d", &numbers[i]);

    // find minimum number in array
    int minIndex = 0;
    for (int i = 0; i < n; i++) if (numbers[minIndex] > numbers[i]) minIndex = i;
    numbers[minIndex]++;

    // calculate
    unsigned long long int producted = 1;
    for (int i = 0; i < n; i++) producted *= numbers[i];

    // standard output
    printf("%llu\n", producted);

    return 0;
}
