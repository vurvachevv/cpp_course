#include <iostream>
#include <vector>

void doubling(std::vector<int>& v)
{
    std::vector<int> v_copy = v;
    v.insert(v.end(), v_copy.begin(), v_copy.end());
}

void print(const std::vector<int>& v)
{
    for (int num : v)
        std::cout << num << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> v {10, 20, 30};
    doubling(v);
    print(v);
}
