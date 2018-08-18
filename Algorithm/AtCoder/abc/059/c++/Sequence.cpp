#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

/// input
int n;
vector<ll> v;

ll solve(int iv) {
    ll cnt, sum, prevSum, add;
    cnt = sum = add = 0;
    prevSum = iv;

    for (int i = 0; i < n; ++i) {
        sum += v[i];

        if (prevSum < 0 && sum <= 0) {
            add = -sum + 1;
            sum += add;
            cnt += llabs(add);

        } else if (prevSum > 0 && sum >= 0) {
            add = -sum - 1;
            sum += add;
            cnt += llabs(add);
        }

        prevSum = sum;
    }

    return cnt;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int a; scanf("%d", &a);
        v.push_back(a);
    }

    printf("%lld\n", min(solve(1), solve(-1)));

    return 0;
}