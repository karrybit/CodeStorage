#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<bool> map(1000000100, false);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        unsigned long a; cin >> a;
        if (map[a]) --cnt;
        else        ++cnt;
        map[a] = !map[a];
    }

    cout << cnt << endl;

    return 0;
}