#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <cmath>

#define BP 1000000007

using namespace std;

typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned int ui;

typedef vector<ull> vull;
typedef vector<ll> vll;
typedef vector<ui> vui;
typedef vector<long> vl;
typedef vector<int> vi;
typedef vector<vl> vvl;
typedef vector<vi> vvi;

typedef pair<ull, ull> pull;
typedef pair<ll, ll> pll;
typedef pair<ui, ui> pui;
typedef pair<long, long> pl;
typedef pair<int, int> pi;

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

template <class T>
void printvv(vector<T> vvc) { 
    for (auto vc: vvc) {
        for (auto e: vc) cout << e << " ";
        cout << endl;
    }
}

int main() {
    int n, a, b; cin >> n >> a >> b;
    string str; cin >> str;

    int pass = 0;
    int bc = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'a') {
            if (pass < a+b) {
                cout << "Yes" << endl;
                ++pass;
            } else {
                cout << "No" << endl;
            }

        } else if (str[i] == 'b') {
            if (pass < a+b && bc < b) {
                ++pass, ++bc;
                cout << "Yes" << endl;

            } else {
                cout << "No" << endl;
            }

        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}