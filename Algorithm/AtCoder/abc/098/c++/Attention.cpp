#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n; cin >> n;
    string str; cin >> str;

    vector<int> e;
    vector<int> w;

    int en, wn; en = wn = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'E') {
            if (i) {
                e.push_back(e[i-1]+1);
                w.push_back(w[i-1]);

            } else {
                e.push_back(1);
                w.push_back(0);
            }

        } else {
            if (i) {
                e.push_back(e[i-1]);
                w.push_back(w[i-1]+1);

            } else {
                e.push_back(0);
                w.push_back(1);
            }
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) ans = min(ans, ((e[n-1] - e[i]) + w[i-1]));

    cout << ans << endl;

    return 0;
}