#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int ret = 0;
    for (; n; n /= 10) if (n % 10) ret++;

    std::cout << ret << std::endl;
    return 0;
}