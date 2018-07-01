#include <iostream>

int main() {
    int ival = 42;
    int *p = &ival;
    std::cout << "value is " << *p << std::endl;
    std::cout << "address is " << p << std::endl;
    return 0;
}
