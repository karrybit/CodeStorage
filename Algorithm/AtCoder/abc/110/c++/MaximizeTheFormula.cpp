#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    cout << max(max(a*10+b+c, a+b*10+c),a+b+c*10) << endl;
    return 0;
}