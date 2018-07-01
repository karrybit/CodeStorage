#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main() {
    int n, l;
    cin >> n >> l;

    vector<string> vs;
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        vs.push_back(word);
    }

    sort(vs.begin(), vs.end());
    for (auto word: vs) cout << word;
    cout << endl;

    return 0;
}
