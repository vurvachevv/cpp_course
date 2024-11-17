#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Number
{
private:
    std::vector<int> digits;

public:
    Number()
    {
        digits.push_back(0);
    }

    Number(const Number& n)
    {
        digits = n.digits;
    }

    Number(const std::string& str)
    {
        for (int i = str.size() - 1; i >= 0; --i)
        {
            digits.push_back(str[i] - '0');
        }
    }

    Number& operator=(const Number& n)
    {
        digits = n.digits;
        return *this;
    }

    Number operator+(const Number& n) const
    {
        Number result;
        int carry = 0;
        int size1 = digits.size();
        int size2 = n.digits.size();
        int maxSize = std::max(size1, size2);

        for (int i = 0; i < maxSize || carry != 0; ++i)
        {
            int sum = carry;
            if (i < size1)
                sum += digits[i];
            if (i < size2)
                sum += n.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
        }

        return result;
    }

    Number& operator+=(const Number& n)
    {
        *this = *this + n;
        return *this;
    }

    bool isEven() const
    {
        return digits[0] % 2 == 0;
    }

    Number operator*(const Number& n) const
    {
        Number result;
        int size1 = digits.size();
        int size2 = n.digits.size();
        result.digits.resize(size1 + size2, 0);

        for (int i = 0; i < size1; ++i)
        {
            int carry = 0;
            for (int j = 0; j < size2 || carry != 0; ++j)
            {
                long long product = result.digits[i + j] + digits[i] * 1LL * (j < size2 ? n.digits[j] : 0) + carry;
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }

        return result;
    }

    void print() const
    {
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            std::cout << digits[i];
        }
        std::cout << std::endl;
    }
};

int main()
{
    // подзадача 3
    Number a("12345678");
    Number b("100000000000000000000000000000000");

    // подзадача 5
    Number c = a + b;
    c.print(); // 10000000012345678

    // подзадача 6
    Number f1("1");
    Number f2("1");
    for (int i = 2; i <= 1000; ++i)
    {
        Number f = f1 + f2;
        f1 = f2;
        f2 = f;
    }
    f2.print(); // F(1000) 

    // подзадача 7
    if (f2.isEven())
    {
        std::cout << "F(1000) is even" << std::endl;
    }
    else
    {
        std::cout << "F(1000) is odd" << std::endl;
    }

    // подзадача 8
    Number fact("1");
    for (int i = 2; i <= 1000; ++i)
    {
        fact = fact * Number(std::to_string(i));
    }
    fact.print(); // 1000!

    // подзадача 9
    class Integer
    {
    private:
        std::vector<int> digits;

    public:
        Integer()
        {
            digits.push_back(0);
        }

        Integer(const Integer& n)
        {
            digits = n.digits;
        }

        Integer(const std::string& str)
        {
            for (int i = str.size() - 1; i >= 0; --i)
            {
                digits.push_back(str[i] - '0');
            }
        }

        Integer& operator=(const Integer& n)
        {
            digits = n.digits;
            return *this;
        }

        Integer operator+(const Integer& n) const
        {
            Integer result;
            int carry = 0;
            int size1 = digits.size();
            int size2 = n.digits.size();
            int maxSize = std::max(size1, size2);

            for (int i = 0; i < maxSize || carry != 0; ++i)
            {
                int sum = carry;
                if (i < size1)
                    sum += digits[i];
                if (i < size2)
                    sum += n.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }

            return result;
        }

        Integer operator*(const Integer& n) const
        {
            Integer result;
            int size1 = digits.size();
            int size2 = n.digits.size();
            result.digits.resize(size1 + size2, 0);

            for (int i = 0; i < size1; ++i)
            {
                int carry = 0;
                for (int j = 0; j < size2 || carry != 0; ++j)
                {
                    long long product = result.digits[i + j] + digits[i] * 1LL * (j < size2 ? n.digits[j] : 0) + carry;
                    result.digits[i + j] = product % 10;
                    carry = product / 10;
                }
            }

            return result;
        }

        void print() const
        {
            for (int i = digits.size() - 1; i >= 0; --i)
            {
                std::cout << digits[i];
            }
            std::cout << std::endl;
        }
    };

    Integer i1("123456789");
    Integer i2("987654321");
    Integer i3 = i1 + i2;
    i3.print(); // 1111111110

}
