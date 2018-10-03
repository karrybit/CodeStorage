#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

int main() {
    string S, T; cin >> S >> T;

    char initial = T[0];

    int q = 0;
    int cnt = 0;
    for (char c: S) {
        if (c == initial)   cnt = 1;
        else if (c == '?')  q = max(q, ++cnt);
        else                cnt = 0;
    }

    return 0;
}
