#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        v.push_back(value);
    }
    
    ++*min_element(v.begin(), v.end());

    unsigned long long ans = 1;
    for (auto e: v) ans *= e;

    cout << ans << endl;

    return 0;
}
