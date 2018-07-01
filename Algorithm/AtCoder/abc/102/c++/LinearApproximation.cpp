#include <cstdio>
#include <vector>
#include <complex>

using std::scanf;
using std::printf;
using std::vector;
using std::abs;

int main() {
    int n, a;
    int indexSum = 0;
    int eleSum = 0;
    scanf("%d", &n);
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        indexSum += i;
        scanf("%d", &a);
        eleSum += a;
        v.push_back(a);
    }

    int size = v.size();
    int b = (eleSum - indexSum) / size;
    int sadPoint = 0;
    for (int i = 0; i < n; i++) {
        int sad = v[i] - (b + i + 1);
        sadPoint += abs(sad);
    }

    printf("%d\n", sadPoint);

    return 0;
}
