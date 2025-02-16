#include <iostream>

struct Book
{
    std::string title;
    int pages;
    float price;
};

bool isExpensive(const Book& b)
{
    return b.price > 1000;
}

int main()
{
    Book b = {"C++ Programming", 500, 1200};
    std::cout << isExpensive(b) << std::endl;
}
