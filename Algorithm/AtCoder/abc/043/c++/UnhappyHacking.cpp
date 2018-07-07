#include <iostream>
#include <cstdio>
#include <string>

int main() {
    std::string str;   std::cin >> str;
    std::string ans;
    for (auto s: str) {
        if (s != 'B') ans += s;
        else if (!ans.empty()) ans.pop_back();
    }
    printf("%s\n", ans.c_str());
    return 0;
}