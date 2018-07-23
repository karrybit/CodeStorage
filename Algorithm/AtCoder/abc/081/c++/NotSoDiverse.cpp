#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int  arr[200010] = {};

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ++arr[a];
    }

    vector<int> v;
    for (int e: arr) v.push_back(e);
    sort(v.begin(), v.end());
    int l;
    if (v.size() - k > 0) l = v.size() - k;
    else                  l = 0;

    int ans = 0;
    for (int i = 0; i < l; i++) ans += v[i];
    
    cout << ans << endl;

    return 0;
}