#include <iostream>

int main() {
    int i, j, k;
    std::cin >> i >> j >> k;
    if ((i == 5 || i == 7) && (j == 5 || j == 7) && (k == 5 || k == 7) && (i + j + k == 17)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
