/* Problem: Find the majority element and return -1 if not found 1 */
#include <iostream>
#include <vector>
#include <unordered_map>

auto checkMajority(const std::vector<int> &vec)
{
    if (vec.empty())
    {
        std::cout << "list is empty !!!" << "\n";
        return -1;
    }
    std::unordered_map<int, int> umap;
    int n = vec.size();
    for (const auto &ch : vec)
    {
        umap[ch]++;
        if (umap[ch] > n / 2)
            return ch;
    }
    return -1;
}

// using boyers mayers algo using candidate and voting logic
int usingBoyers(const std::vector<int> &vec)
{
    if (vec.empty())
    {
        std::cout << "Input list is empty...!!! \n";
        return -1;
    }
    int n = vec.size();
    int candidate = -1, count = 0;
    for (const auto &i : vec)
    {
        if (count == 0)
        {
            candidate = i;
            count = 1;
        }
        else if (i == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (const auto &i : vec)
    {
        if (i == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;
    else
        return -1;
}

int main()
{
    std::vector<int> vec = {1, 3, 3, 4, 3, 3};
    // int result = checkMajority(vec);
    int result = usingBoyers(vec);
    (result != -1 ? (std::cout << "Majority element is: " << result) : (std::cout << "No Majority element found !!!"));
    std::cout << "\n";
    return 0;
}