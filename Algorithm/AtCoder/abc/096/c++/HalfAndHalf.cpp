#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    // ab2枚のコストとa+bのコストの大小が鍵
    int cc = c * 2;
    int ab = a + b;

    // c2枚とa+bの比較すれば即買いの枚数を計算
    // というか共通した枚数を計算、zとする
    int z = min(x, y);

    unsigned long long ans = 0;
    // c2枚買うより、aとbを買う方が安いなら、その方が良いよね
    ans += ab <= cc ? ab * z : cc * z;
    // c2枚買って余らせるより、aを素直に買ったほうが安いなら、その方が良いよね
    ans += a <= cc ? (x - z) * a : (x - z) * cc;
    // c2枚買って余らせるより、bを素直に買ったほうが安いなら、その方が良いよね
    ans += b <= cc ? (y - z) * b : (y - z) * cc;

    cout << ans << endl;

    return 0;
}