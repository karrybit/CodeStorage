#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ue;
    vector<int> shita;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (!i) ue.push_back(a);
        else {
            ue.push_back(ue[i-1]+a);
        }
    }

    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        if (!i) shita.push_back(ue[i] + a);
        else {
            shita.push_back(max(ue[i]+a, shita[i-1]+a));
        }
    }

    cout << shita[n-1] << endl;

    return 0;
}