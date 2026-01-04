#include <bits/stdc++.h>
using namespace std;

void longestSubArrayOfTargetSum(const vector<int> &arr, int target, vector<pair<int, int>> &result)
{
    int left = 0, maxlen = 0, sum = 0;

    for (int i = 0; i < (int)arr.size(); i++)
    {
        sum += arr[i];

        while (sum > target && left <= i)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == target)
        {
            int currentLen = i - left + 1;
            if (currentLen > maxlen)
            {
                maxlen = currentLen;
                result.clear();
                for (int j = left; j <= i; j++)
                {
                    result.push_back({j, arr[j]});
                }
            }
            else
            {
                cout << "No better subarray found at indices: " << left << " to " << i << endl;
            }
        }
    }
}

// 2nd approach using hashmap to store prefix sums
void longestSubArrayOfTargetSum_HashMap(const vector<int> &arr, int target, vector<pair<int, int>> &result)
{
    printf("\n=== HashMap Approach: Starting with target=%d ===\n", target);
    unordered_map<int, int> prefixSumIndex;
    prefixSumIndex[0] = -1; // Handle subarrays starting at index 0
    int sum = 0, maxlen = 0;

    // keep inserting elements to a loop
    // if sum - target, need found in the map, then check length and move left by 1
    for (int right = 0; right < arr.size(); right++)
    {
        sum += arr[right];
        int need = sum - target;

        printf("\n[Index %d] arr[%d]=%d, sum=%d, need=%d\n", right, right, arr[right], sum, need);

        if (prefixSumIndex.count(need))
        {
            int startIdx = prefixSumIndex[need] + 1;
            int currentlen = right - startIdx + 1;
            printf("  -> FOUND: need=%d at index %d\n", need, prefixSumIndex[need]);
            printf("  -> Subarray [%d..%d] sums to %d (length=%d)\n", startIdx, right, target, currentlen);

            if (currentlen > maxlen)
            {
                maxlen = currentlen;
                printf("  -> NEW BEST! Updated maxlen to %d\n", maxlen);
                result.clear();
                for (int j = startIdx; j <= right; j++)
                {
                    result.push_back({j, arr[j]});
                }
            }
            else
            {
                printf("  -> Not better than current maxlen=%d\n", maxlen);
            }
        }

        // Store only first occurrence to maximize length
        if (prefixSumIndex.find(sum) == prefixSumIndex.end())
        {
            prefixSumIndex[sum] = right;
            printf("  -> Stored prefixSum[%d] = %d (first occurrence)\n", sum, right);
        }
        else
        {
            printf("  -> prefixSum[%d] already exists at index %d (keeping earliest)\n", sum, prefixSumIndex[sum]);
        }
    }
    printf("\n=== HashMap Result: maxlen=%d ===\n\n", maxlen);
}

int main()
{
    vector<int> arr = {1, 2, 3, 7, -5, -2, 1, 4, 3, 2};
    int target = 12;
    vector<pair<int, int>> result;
    // longestSubArrayOfTargetSum(arr, target, result);
    // if (!result.empty())
    // {
    //     cout << "Longest subarray(s) with target sum " << target << " found at indices:\n";
    //     for (const auto &p : result)
    //     {
    //         cout << "[" << p.first << ", " << p.second << "]\n";
    //     }
    // }
    // else
    // {
    //     cout << "No subarray found with target sum " << target << ".\n";
    // }

    longestSubArrayOfTargetSum_HashMap(arr, target, result);
    if (!result.empty())
    {
        cout << "Longest subarray(s) with target sum " << target << " found at indices using HashMap approach:\n";
        for (const auto &p : result)
        {
            cout << "[" << p.first << ", " << p.second << "]\n";
        }
    }
    else
    {
        cout << "No subarray found with target sum " << target << " using HashMap approach.\n";
    }
    return 0;
}