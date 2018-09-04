#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    int cost, sx, sy, dx, dy;
    sx = sy = 0;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        cin >> cost >> dx >> dy;
        if (!flag) continue;
        int diff = (dx - sx) + (dy - sy);
        if (diff > cost) {
            flag = false;
            continue;
        }

        if ((cost - diff )% 2 != 0) {
            flag = false;
            continue;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;

    return 0;
}