#include <iostream>
#include <string>

std::string repeat(int n)
{
    if (n <= 0) return "";
    std::string result = std::to_string(n);
    return std::string(n, result[0]);
}

int main()
{
    std::cout << repeat(5) << std::endl;
    std::cout << repeat(10) << std::endl;
    std::cout << repeat(-1) << std::endl;
}
