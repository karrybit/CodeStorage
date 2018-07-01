/*
 * ユーザーに2つの整数の入力を求め、それらの整数によって定義される範囲の数字をそれぞれ出力するプログラムを作成せよ
*/

#include <iostream>

int main() {
    int l, u;
    std::cout << "Enter two numbers" << std::endl;
    std::cout << "Lower bound is?" << std::endl;
    std::cin >> l;
    std::cout << "Upper bound is?" << std::endl;
    std::cin >> u;
    std::cout << "↓↓↓These numbers are the numbers what are within the range of your inputs↓↓↓" << std::endl;
    while (l <= u) {
        std::cout << l << std::endl;
        l++;
    }
    return 0;
}
