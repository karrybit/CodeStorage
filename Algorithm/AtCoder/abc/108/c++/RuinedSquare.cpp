#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int x3, y3, x4, y4;
    x3 = y3 = x4 = y4 = 0;

    int diffX, diffY;
    diffX = diffY = 0;
    
    diffX = x2 - x1;
    diffY = y2 - y1;

    x3 = x2 - diffY;
    y3 = y2 + diffX;

    diffX = x3 - x2;
    diffY = y3 - y2;

    x4 = x3 - diffY;
    y4 = y3 + diffX;

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl; 

    return 0;
}