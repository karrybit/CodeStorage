#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    long long ans = 0;
    for (int e: v) ans += e;
    ans -= n;

    cout << ans << endl;

    return 0;
}