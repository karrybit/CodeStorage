#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

int main() {
    int n;   scanf("%d", &n);
    std::vector<int> vc;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        vc.push_back(a);
    }

    long cost = LONG_MAX;
    for (int i = -100; i <= 100; i++) {
        long powed = 0;
        for (auto a: vc) {
            powed += std::pow(a - i, 2);
        }
        cost = std::min(cost, powed);
    }

    std::cout << cost << std::endl;

    return 0;
}