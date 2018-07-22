#include <iostream>
#include <chrono>

using namespace std;

int main() {
    int n, y;
    cin >> n >> y;

    auto start = chrono::system_clock::now();

    long ans = 0;
    bool breakFlag = false;
    int mn = n;
    int gn = 0;
    int sn = 0;
    for (int mi = n; mi >= 0; --mi) {
        int diff = n - mi;
        for (int gi = 0; gi <= diff; ++gi) {
            ans = mi * 10000 + gi * 5000 + (diff - gi) * 1000;
            if (ans == y) {
                mn = mi;
                gn = gi;
                sn = n - mn - gn;
                breakFlag = true;
                break;
            }
        }

        if (breakFlag) {
            break;
        }

        mn = -1;
        gn = -1;
        sn = -1;
    }

    cout << mn << " " << gn << " " << sn << endl;

    auto end = chrono::system_clock::now();
    auto msec = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//    cout << msec << " milli sec" << endl;

    return 0;
}