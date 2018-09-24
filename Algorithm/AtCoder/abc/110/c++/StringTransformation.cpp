#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <climits>
#include <queue>

using namespace std;

string S, T;

int cnt[26];
int to[26];

void change(int i) {
    char s = S[i], t = T[i];
    for (int j = i; j < S.size(); ++j) {
        if (S[j] == s) S[j] = t;
        else if (S[j] == t) S[j] = s;
    }
}

int main() {
    cin >> S >> T;

    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    int idx = 0;
    for (int i = 0; i < S.size(); ++i) {
        ++cnt[S[i]];
        if (S[i] != T[i]) change(i);
    }

    cout << (S == T ? "Yes" : "No") << endl;

    return 0;
}