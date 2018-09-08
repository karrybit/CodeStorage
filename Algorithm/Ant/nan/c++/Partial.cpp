#include <iostream>
#include <vector>

using namespace std;

bool loop(int, int);

int n;
vector<int> vc;
int k;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        vc.push_back(a);
    }
    vc.push_back(0);
    cin >> k;

    cout << (loop(0, 0) ? "Yes" : "No") << endl;

    return 0;
}

bool loop(int depth, int v) {
    if (v == k) return true;
    if (depth == n) return false;
    return loop(depth + 1, v) || loop(depth + 1, v + vc[depth + 1]) ;
}