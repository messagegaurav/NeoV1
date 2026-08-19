/* Problem Statement: Two Sum i.e. given an integer array and a target
need to find numbers that adds up to the target */
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <unordered_map>

// using vector: cons - using find inside a loop hits badly the peformance
// also it gives duplicate results - not correct
std::vector<std::pair<int, int>> findTwoSum(const std::vector<int> &arr)
{
    std::vector<std::pair<int, int>> result;
    if (arr.empty())
    {
        std::cout << "No inputs provided ...!!!" << "\n";
        result.push_back(std::make_pair(-1, -1));
        return result;
    }

    int target;
    std::cout << "Enter target: ";
    std::cin >> target;

    for (int i = 0; i < arr.size(); i++)
    {
        int diff = target - arr[i];
        auto itr = std::find(arr.begin(), arr.end(), diff);
        if (itr != arr.end())
        {
            result.push_back(std::make_pair(arr[i], *itr));
        }
    }
    return result;
}

// using map now to get better complexity
void findTwoSumUsingMap(const std::vector<int> &arr)
{
    std::unordered_map<int, int> Map;
    if (arr.empty())
    {
        std::cout << "No inputs provided ...!!!" << "\n";
        Map[-1] = -1;
    }
    int target;
    std::cout << "Enter target: ";
    std::cin >> target;
    for (int i = 0; i < arr.size(); i++)
    {
        int diff = target - arr[i];
        if (Map.find(diff) != Map.end())
        {
            std::cout << "Indices are: " << Map[arr[i]] << " , " << i << "\n";
            std::cout << "Values are: " << arr[Map[arr[i]]] << " , " << arr[i] << "\n";
        }
        Map[arr[i]] = i;
    }
}

int main()
{
    std::vector<int> arr = {5, 2, 9, 4, 6, 8};

    auto result = findTwoSum(arr);
    std::cout << "Result: " << "\n";
    for (const auto &ch : result)
    {
        std::cout << ch.first << " , " << ch.second << "\n";
    }
    findTwoSumUsingMap(arr);
    std::cout << "\n";
    return 0;
}