#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;
    if (n * m % 2 == 0)   std::cout << "Even" << std::endl;
    else                  std::cout << "Odd" << std::endl;
    return 0;
}