#include <iostream>
#include <string>
#include <vector>

std::vector<std::size_t> substringIndexes(const std::string& str, const std::string& sub)
{
    std::vector<std::size_t> indexes;
    size_t pos = str.find(sub);
    while (pos != std::string::npos)
    {
        indexes.push_back(pos);
        pos = str.find(sub, pos + 1);
    }
    return indexes;
}

void print(const std::vector<std::size_t>& v)
{
    for (std::size_t i : v)
        std::cout << i << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<std::size_t> v1 = substringIndexes("cat and dog and cat", "cat");
    print(v1);
}
