#include <iostream>
#include <vector>

using namespace std;

int main() {
    int base;   cin >> base;
    vector<int> v;
    
    for (int n = 2; n < base; n++) {
        bool ok = true;
        for (int k1 = 0; k1 < base; k1++) {
            for (int k2 = 0; k2 < base; k2++) {
                for (int k3 = 0; k3 < base; k3++) {
                    if ((k1 + k2 * base + k3 * base * base) % n == 0 && (k1 + k2 + k3) % n != 0) {
                        ok = false;
                        break;
                    }
                }
                if (!ok) break;
            }
            if (!ok) break;
        }
        if (ok) v.push_back(n);
    }

    for (auto e: v) cout << e << endl;

    return 0;
}
