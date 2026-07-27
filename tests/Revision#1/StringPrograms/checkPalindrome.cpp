#include <iostream>
#include <climits>

/* this one checks for simple string */
bool checkPalindrome(const std::string &text)
{
    if (text.empty())
    {
        std::cout << "Entered string is empty..!!!" << "\n";
        return false;
    }
    int n = text.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (text[i] != text[n - i - 1])
        {
            return false;
        }
    }
    return true;
}

/* finding longest palindrome substring */
std::string findLongPalindrome(const std::string &source)
{
    // start from the centre of the string
    // expand one right and one left
    // keep expanding until it remains palindrome
    // return the max length
    /* it was a good idea, only thing you cant start from the centre instead
    start with left and right + 1 and likewise once match found keep on expanding the window*/

    if (source.empty())
    {
        std::cout << "Entered string is empty !!!" << "\n";
        return "";
    }

    int n = source.size();
    int maxLen = 0, start = 0;
    auto expand = [&](int left, int right)
    {
        while ((left >= 0 && right < n) && (source[left] == source[right]))
        {
            if (maxLen < right - left + 1)
            {
                maxLen = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    };

    for (int i = 0; i < n; i++)
    {
        expand(i, i);     // for odd length
        expand(i, i + 1); // for even length
    }
    return (maxLen == 0 ? "" : source.substr(start, maxLen));
}

int main()
{
    const std::string text("ladpeepbc");
    std::cout << findLongPalindrome(text) << "\n";
    return 0;
}