#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 5; // 1<<n : 0b100000

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) {

        // bit の表す集合を求める
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            // i番目のbitが立っていれば、iをpush_backする
            if (bit & (1<<i)) S.push_back(i);
        }

        if (bit < 10) cout << bit << ":  { ";
        else          cout << bit << ": { ";
        
        // bit の表す集合の出力
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }

        cout << "}" << endl;
    }
}