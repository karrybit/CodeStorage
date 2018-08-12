#import <iostream>
#import <vector>
#import <algorithm>

using namespace std;

int main() {
    int L, n;
    cin >> L >> n;

    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }

    int minT, maxT;

    for (int i = 0; i < n; ++i) {
        minT = max(minT, min(v[i], L - v[i]));
        maxT = max(maxT, max(v[i], L - v[i]));
    }

    cout << "min = " << minT << endl;
    cout << "max = " << maxT << endl;

    return 0;
}