#include <iostream>
#include <string>

using namespace std;

const string DREAM   = "dream";
const string DREAMER = "dreamer";
const string ERASE   = "erase";
const string ERASER  = "eraser";

string str;
string target = "";

bool concat(int from, int to) {
    if (target == str) return true;
    if (to >= str.length()) return false;
    for (int i = from; i < to; i++) if (target[i] != str[i]) return false;

    target += DREAM;
    bool dream = concat(to , to + 5);
    for (int i = 0; i < 5; i++) target.pop_back();

    target += DREAMER;
    bool dreamer = concat(to, to + 7);
    for (int i = 0; i < 7; i++) target.pop_back();

    target += ERASE;
    bool erase = concat(to, to + 5);
    for (int i = 0; i < 5; i++) target.pop_back();

    target += ERASER;
    bool eraser = concat(to, to + 6);
    for (int i = 0; i < 6; i++) target.pop_back();

    if (dream || dreamer || erase || eraser) return true;
    else                                     return false;
}

int main() {
    cin >> str;

    if (concat(0, 0)) cout << "YES" << endl;
    else                  cout << "NO" << endl;

    return 0;
}