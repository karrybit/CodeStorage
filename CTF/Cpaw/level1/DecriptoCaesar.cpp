#include <iostream>
#include <string>

using namespace std;

int main() {
    string cpaw = "fsdz";
    string flag = "Fdhvdu_flskhu_lv_fodvvlfdo_flskhu";

    int diff = 'c' - cpaw.front();
    for (char &c: flag) c += diff;

    cout << flag << endl;

    return 0;
}