#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

void print(const std::vector<int>& v)
{
    for (int num : v)
        std::cout << num << " ";
    std::cout << std::endl;
}

void print(const int* a, std::size_t n)
{
    for (std::size_t i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

char& get(std::string& str, int index)
{
    if (index < 0 || index >= str.size())
        std::exit(1);
    return str[index];
}

int& get(std::vector<int>& v, int index)
{
    if (index < 0 || index >= v.size())
        std::exit(1);
    return v[index];
}

int& get(int* a, std::size_t n, int index)
{
    if (index < 0 || index >= n)
        std::exit(1);
    return a[index];
}

int main()
{
    std::vector<int> v {10, 20, 30, 40, 50};
    get(v, 2) += 1;
    print(v);

    std::string s = "Cat";
    get(s, 0) = 'B';
    std::cout << s << std::endl; 

    int a[5] = {10, 20, 30, 40, 50};
    get(a, 5, 2) += 1;
    print(a, 5); 
    get(v, 10) = 0;
}
