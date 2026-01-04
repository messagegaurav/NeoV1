#include <bits/stdc++.h>
using namespace std;

// t: O(n)  s: O(1)
void FindTwoSum(vector<int> &arr, int target, vector<pair<int, int>> &res)
{
    unordered_map<int, int> mp;
    int need = 0;
    int left = 0, maxlen = 0;
    for (int right = 0; right < arr.size(); right++)
    {
        need = target - arr[right];
        if (mp.count(need))
        {
            cout << "Pair found: (" << mp[need] << ", " << right << ")\n";
            res.push_back({mp[need], right});
        }
        // if need found add it to the results
        // keep moving forward
        // store indexes in map for sum

        mp[arr[right]] = right;
    }
}

// t: O(n^2) s: O(1)
void findingLargestSubarrayWithSumK(vector<int> &arr, int target, vector<pair<int, int>> &result)
{
    int sum = 0, maxlen = 0;
    int left = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];

        // Shrink the window if the sum exceeds the target
        while (sum > target && left <= right)
        {
            sum -= arr[left];
            left++;
        }

        // Check if the current window matches the target
        if (sum == target)
        {
            int len = right - left + 1;
            if (len > maxlen)
            {
                maxlen = len;
                result.clear(); // Clear previous results if a new max length is found
                result.push_back({left, right});
                cout << "New max length " << maxlen << " for subarray (" << left << ", " << right << ")\n";
            }
            else if (len == maxlen)
            {
                // If the length matches the current max length, add the subarray
                result.push_back({left, right});
                cout << "Another subarray with max length " << maxlen << ": (" << left << ", " << right << ")\n";
            }
        }
    }
}

// t: O(n)  s: O(n)
void findingMaxUsingHash(vector<int> &arr, int target, vector<pair<int, int>> &result)
{
    unordered_map<int, int> mp;
    mp[0] = -1;
    int sum = 0, need = 0;
    int left = 0, maxlen = 0;

    for (int right = 0; right < arr.size(); right++)
    {
        // add the sum
        sum += arr[right];
        cout << "Right: " << right << ", Current Element: " << arr[right] << ", Sum: " << sum << endl;

        // calculate need
        need = sum - target;
        cout << "Need: " << need << endl;

        // check if need exists in the map
        if (mp.count(need))
        {
            cout << "Found need: " << need << " at index " << mp[need] << endl;
            int len = right - mp[need];
            cout << "Length of subarray: " << len << endl;

            if (len >= maxlen)
            {
                maxlen = len;
                result.push_back({mp[need] + 1, right});
                cout << "New max length: " << maxlen << " for subarray (" << mp[need] + 1 << ", " << right << ")\n";
            }
        }

        // store the current sum and index in the map
        mp[sum] = right;
        cout << "Stored in map: Sum = " << sum << ", Index = " << right << endl;
    }
}

// t: O(n) s: O(1)
void longestSubArrayChar(string str)
{
    int left = 0, right = 0;
    unordered_map<char, int> charIndexMap;
    int maxlen = 0;
    for (int right = 0; right < str.length(); right++)
    {
        char c = str[right];

        if (charIndexMap.count(c) && charIndexMap[c] >= left)
        {
            left = charIndexMap[c] + 1;
            int len = right - left + 1;
            if (len > maxlen)
            {
                maxlen = len;
                cout << "New max length: " << maxlen << " for substring \"" << str.substr(left, len) << "\"\n";
            }
        }
        charIndexMap[c] = right;
    }
}

int main()
{
    vector<int> arr = {10, 2, 3, 8, 5, 2, -6, 8, 7, 12, -4, 10, 5, 2, 3, 5};
    // vector<int> arr = {10, 15, 3, 7, 2, 11, 9};
    unordered_map<int, int> mp;
    int target = 15;
    vector<pair<int, int>> res;
    // FindTwoSum(arr, target, res);
    // for (auto &p : res)
    // {
    //     cout << p.first << " + " << p.second << " = " << target << endl;
    // }
    // findingLargestSubarrayWithSumK(arr, target, res);
    // for (auto &p : res)
    // {
    //     cout << "Subarray with sum " << target << ": (" << p.first << ", " << p.second << ")\n";
    // }
    // findingMaxUsingHash(arr, target, res);
    // for (auto &p : res)
    // {
    //     cout << "Subarray with sum " << target << ": (" << p.first << ", " << p.second << ")\n";
    // }
    longestSubArrayChar("abcabcedb");
    return 0;
}