#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

pair<int, int> findSum(const vector<int> &vec, int target)
{
    pair<int, int> Pair = {0, 0};
    unordered_map<int, int> Map;
    if (vec.empty())
        return {-1, -1};

    int len = (int)vec.size();

    for (int i = 0; i < len; i++)
    {
        int complement = target - vec[i];
        if (Map.find(complement) != Map.end())
        {
            Pair = {Map[complement], i};
            return Pair;
        }
        Map[vec[i]] = i;
    }
    return {-1, -1};
}

int main()
{
    vector<int> vec = {2, -3, 5, 6, 10, 0, -1};
    pair<int, int> result = findSum(vec, 15);
    cout << " Target: 15    " << "indices: " << result.first << " : " << result.second << endl;
    vector<int> nums2 = {3, 2, 4};
    result = findSum(nums2, 6); // [1, 2]
    cout << " Target: 6    " << "indices: " << result.first << " : " << result.second << endl;

    vector<int> nums3 = {3, 2};
    result = findSum(nums3, 6);
    cout << " Target: 6    " << "indices: " << result.first << " : " << result.second << endl;
    return 0;
}