#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> vc;
    char c;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;

        if (!ok) continue;

        if (i > 0 && c != str[0]){
            ok = false;
            continue;
        } 

        auto result = find(vc.begin(), vc.end(), str);
        ok = result == vc.end();

        vc.push_back(str);
        c = str.back();
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}