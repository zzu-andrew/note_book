#include <cctype>
#include <string>
#include <iostream>

int isNumber(const std::string& str) {
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return 0;
    }
    return str.length();
}
int main() {
    std::string str1 = "";
    std::string str2 = "1234a";

    std::cout << "Length of str1 is: " << isNumber(str1) << std::endl;  // Outputs: Length of str1 is: 5
    std::cout << "Length of str2 is: " << isNumber(str2) << std::endl;  // Outputs: Length of str2 is: 0


    return 0;
}