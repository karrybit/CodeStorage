#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int v[6] = {1, 5, 10, 50, 100, 500};

int main() {
    vector<int> coins(6, 0);
    int A;
    for (int i = 0; i < 6; ++i) cin >> coins[i];
    cin >> A;

    int cnt = 0;
    for (int i = 5; i >= 0; --i) {
        int t = min(A / v[i], coins[i]);
        A -= t * v[i];
        cnt += t;
    }

    cout << cnt << endl;

    return 0;
}