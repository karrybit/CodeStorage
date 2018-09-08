#include <iostream>
#include <vector>
#include <string>

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

        for (string e: vc) {
            if (str == e) {
                ok = false;
                continue;
            }
        }

        vc.push_back(str);
        c = str[str.size() - 1];
    }

    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}