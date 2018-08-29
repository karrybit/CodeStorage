#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vc;
int salaries[64];


int main() {
    int n; cin >> n;
    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        vc.push_back(str);
    }

    // 給料を初期化
    for (int i = 0; i < n; ++i) salaries[i] = 0;

    return 0;
}