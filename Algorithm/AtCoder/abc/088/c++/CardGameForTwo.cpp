#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;  cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), greater<int>());

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) ret += v[i];
        else            ret -= v[i];
    }

    cout << ret << endl;

    return 0;
}