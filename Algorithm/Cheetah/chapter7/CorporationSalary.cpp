#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> vc;
int salaries[64];
int n;

int memo(int);

int main() {
    cin >> n;
    string str;

    for (int i = 0; i < n; ++i) {
        cin >> str;
        vc.push_back(str);
    }

    // 給料を初期化
    for (int i = 0; i < n; ++i) salaries[i] = 0;

    int ans = 0;
    for (int i = 0; i < n; ++i) ans += memo(i);

    cout << ans << endl;

    return 0;
}

int memo(int index) {
    // すでに計算済みであれば、それを返却する
    if (salaries[index] != 0) return salaries[index];    
    int salary = 0;
    for (int i = 0; i < n; ++i) if (vc[index][i] == 'Y') salary += memo(i);
    return salaries[index] = (salary == 0 ? 1 : salary);
}