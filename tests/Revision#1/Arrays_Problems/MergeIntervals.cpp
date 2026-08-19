/* problem statement: merge intervals example if i/p is [1,4] [2,3] [5,9] [7,8] then o/p : [1,4] [5,9]*/
#include <iostream>
#include <vector>
#include <algorithm>

auto mergeIntervals(std::vector<std::pair<int, int>> &vec)
{
    std::vector<std::pair<int, int>> result;
    if (vec.empty())
    {
        std::cout << "Input list is empty ... !!!! \n";
        return result;
    }
    std::sort(vec.begin(), vec.end());
    auto current = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        if (current.second < vec[i].first)
        {
            // good scenario
            result.push_back(current);
            current = vec[i];
        }
        else if (current.second >= vec[i].first)
        {
            std::cout << "hit !!!\n";
            current.second = std::max(vec[i].second, current.second);
        }
    }
    result.push_back(current);

    return result;
}

int main()
{
    std::vector<std::pair<int, int>> vec = {{1, 4}, {5, 9}, {2, 3}, {7, 8}};
    auto myvec = mergeIntervals(vec);
    if (!myvec.empty())
    {
        for (const auto &ch : myvec)
        {
            std::cout << ch.first << "," << ch.second << "\n";
        }
    }
    else
    {
        std::cout << "Nothing to show off \n";
    }
    return 0;
}