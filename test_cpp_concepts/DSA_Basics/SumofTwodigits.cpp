#include <bits/stdc++.h>

using namespace std;

// sort the array
// loop until the value is not greater than the target number
// keep adding the two number to see the sum

void findingSum(const vector<int> &arr, int target, vector<pair<int, int>> &result)
{
    unordered_map<int, int> valueToIndex;
    bool found = false;
    for (int i = 0; i < arr.size(); ++i)
    {
        int complement = target - arr[i];
        if (valueToIndex.count(complement))
        {
            int j = valueToIndex[complement];
            // Store indices and values
            result.push_back({j, i});
            cout << "The two numbers are: " << arr[j] << " (index " << j << ") and " << arr[i] << " (index " << i << ")" << endl;
            found = true;
        }
        valueToIndex[arr[i]] = i;
    }
    if (!found)
    {
        cout << "No pairs found that sum to target." << endl;
    }
}

void twoSum(vector<int> &nums, int target, vector<pair<int, int>> &result)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int need = target - nums[i];

        if (mp.count(need))
        {
            result.push_back({mp[need], i});
        }

        mp[nums[i]] = i;
    }
}

int main()
{
    vector<int> arr = {10, 15, 3, 7, 2, 11, 9};
    int target = 17;
    vector<pair<int, int>> result;
    // findingSum(arr, target, result);
    // for (const auto &p : result)
    // {
    //     cout << "Pair indices: " << p.first << ", " << p.second << " | Values: " << arr[p.first] << ", " << arr[p.second] << "\n";
    // }

    twoSum(arr, target, result);
    for (const auto &p : result)
    {
        cout << "Pair indices: " << p.first << ", " << p.second << " | Values: " << arr[p.first] << ", " << arr[p.second] << "\n";
    }
    return 0;
}