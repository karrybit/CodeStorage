#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> P;

int main() {
    int n, m; cin >> n >> m;
    vector<P> bridges;
    bridges.resize(m);    
    for (int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;
        bridges[i] = P(l, r);
    }
    return 0;
}