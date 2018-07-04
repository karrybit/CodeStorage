#include <cstdio>
#include <vector>
#include <complex>
#include <algorithm>

using namespace std;

int main() {
    long long int n, a;
    scanf("%lld", &n);
    vector<long long int> v;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a);
        v.push_back(a - i);
    }

    sort(v.begin(), v.end());
    long long int size = v.size();
    long long int m = v[size / 2];
    long long int sad = 0;
    for (long long int e: v) sad += abs(e - m);

    printf("%lld\n", sad);

    return 0;
}
