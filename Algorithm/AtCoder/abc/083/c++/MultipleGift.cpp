#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
    ll x, y;
    scanf("%lld %lld", &x, &y);

    int cnt = 0;
    for (; y >= x; x *= 2) ++cnt;

    printf("%d\n", cnt);

    return 0;
}