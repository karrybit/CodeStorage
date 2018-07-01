#include <iostream>

int main() {
    int i = 10;
    int &r = i;
    int *p = &i;
    std::cout << "i value is " << i << std::endl;
    std::cout << "i address is " << &i << std::endl;
    std::cout << "r value is " << r << std::endl;
    std::cout << "r address is " << &r << std::endl;
    std::cout << "p value is " << p << std::endl;
    std::cout << "p address is " << &p << std::endl;
    return 0;
}
