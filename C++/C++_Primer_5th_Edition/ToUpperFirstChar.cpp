#include <iostream>
#include <string>

int main() {
    std::string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();
        *it = toupper(*it);
    }
    std::cout << s << std::endl;
    return 0;
}