#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string str = "abc12def3jh456";
    std::string target = "1234";
    int num = 0;
    int sum = 0;
    for (auto &ch : str)
    {
        if (isdigit(ch))
        {
            num = num * 10 + (ch - '0');
        }
        else
        {
            std::cout << "sum : " << sum << "   num: " << num << "\n";
            sum = sum + num;
            num = 0;
        }
    }
    sum += num;
    std::cout << "final value: " << num << " and its sum = " << sum << "\n";

    int value = stoi(target);
    std::cout << "Int value: " << value << "\n";

    std::string ptr = std::to_string(value);
    std::cout << "String is: " << ptr << "\n";
    return 0;
}