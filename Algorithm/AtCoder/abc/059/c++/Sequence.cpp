#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;
    long long ans, sum;
    ans = sum = 0;
    bool isOldSumPositive = false;
    bool isNewSumPositive = false;
    for (int i = 0; i < n; ++i) {
        long long a; cin >> a;
        isOldSumPositive = sum > 0;
        sum += a;
        isNewSumPositive = sum > 0;

        if (!i) continue;

        if (isOldSumPositive == isNewSumPositive) {

        } 
    }



    return 0;
}