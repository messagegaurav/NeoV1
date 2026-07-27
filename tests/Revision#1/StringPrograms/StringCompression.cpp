#include <iostream>
#include <string>

/* problem statement: input: AAAABBCCCCDDD then output should be A4B2C4D3*/
std::string compress(std::string &text)
{
    std::string result = "";
    int i = 0;
    while (i < text.size())
    {
        int count = 1;
        while ((text[i] == text[i + 1]) && (i + 1 < text.size()))
        {
            count++;
            i++;
        }
        result = result + text[i] + std::to_string(count);
        i++;
    }
    return result;
}
int main()
{
    std::string text = "AAAABBACCCCBBBDDD";
    std::cout << "Compressed string is: " << compress(text) << "\n";
    return 0;
}