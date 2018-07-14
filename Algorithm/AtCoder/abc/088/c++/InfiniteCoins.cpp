#include <iostream>

int main() {
    int n, a;
    std::cin >> n >> a;
    n %= 500;
    if (n > a)  std::cout << "No" << std::endl;
    else        std::cout << "Yes" << std::endl;
    return 0;
}