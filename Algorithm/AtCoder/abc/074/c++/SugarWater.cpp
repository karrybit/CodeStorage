#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, r, capacity;
    cin >> a >> b >> c >> d >> r >> capacity;

    int w = 0, s = 0;
    int maxS = -1;
    for (int i = 1; i < 30; ++i) {
        if (100 * a * i > capacity) break;
        for (int j = 0; j < 30; ++j) {
            if (100 * a * i + 100 * b * j > capacity) break;
            int _w = 100 * a * i + 100 * b * j;
            for (int k = 0; c * k * 100 / (w + c * k) < r; ++k) {
                if (_w + c * k > capacity) break;
                for (int l = 0; ((c * k + d * l) * 100 / (_w + c * k + d * l)) < r; ++l) {
                    if (_w + c * k + d * l > capacity) break;
                    int hoge = ((c * k + d * l) * 100 / (_w + c * k + d * l));
                    cout << _w << ", " << c * k << ", " << d * l << ", " << maxS << ", " << hoge << endl;
                    if (hoge <= r && hoge > maxS) {
                        maxS = hoge;
                        w = _w;
                        s = c * k + d * l;
                    }
                }
            }
        }
    }

    cout << w + s << " " << s << endl;

    return 0;
}