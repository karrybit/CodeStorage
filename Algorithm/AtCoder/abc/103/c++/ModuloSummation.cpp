#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    int c = a % b;
    if (c) {
        return gcd(b, c);
    } else {
        return b;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<int>());

    int gcdValue = (v[0] / gcd(v[0], v[1])) * v[1];
    --gcdValue;

    long ans = 0;
    for (int e: v) ans += gcdValue % e;

    cout << ans << endl;

    return 0;
}