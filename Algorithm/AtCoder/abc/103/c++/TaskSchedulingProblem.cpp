#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v;
    for (int i = 0; i < 3; i++) {
        int task;
        cin >> task;
        v.push_back(task);
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 1; i < 3; i++) {
        ans += v[i] - v[i  - 1];
    }

    cout << ans << endl;

    return 0;
}