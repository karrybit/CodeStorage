#include <iostream>

int main() {
    int v;
    std::cin >> v;
    if (v % 2 == 0) std::cout << v << std::endl;
    else std::cout << v * 2 << std::endl;
    return 0;
}
