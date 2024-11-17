#include <iostream>
#include <cctype>

void countLetters(const std::string& str, int& numLetters, int& numDigits)
{
    numLetters = 0;
    numDigits = 0;
    for (char ch : str)
    {
        if (std::isalpha(ch))
            numLetters++;
        else if (std::isdigit(ch))
            numDigits++;
    }
}

int main()
{
    std::string str = "Hello123";
    int numLetters = 0, numDigits = 0;
    countLetters(str, numLetters, numDigits);
    std::cout << numLetters << " " << numDigits << std::endl;
}
