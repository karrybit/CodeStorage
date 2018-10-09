#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>
#include <bitset>
#include <map>

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

template <class T>
void printv(vector<T> vc) {
    for (auto e: vc) cout << e << " ";
    cout << endl;
}

int D[10];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
        int d; cin >> d;
        D[d] = 1;
    }

	for (int i = n; i < 100000; i++) {
		string S = to_string(i);

        bool isDislike = false;
		for (int j = 0; j < S.size(); j++) {
			if (D[(S[j] - '0')] == 1) {
                isDislike = true;
                break;
            }
		}

        if (isDislike) continue;
		cout << i << endl; break;
	}

    return 0;
}
