/* problem statement: find maximum subarray sum from subsequence */

#include <iostream>
#include <vector>
#include <climits>

int findMaxSum(std::vector<int> arr)
{
    if (arr.empty())
    {
        std::cout << "Input array is empty..!!!" << "\n";
        return INT_MIN;
    }

    int n = arr.size();
    int maxSum = INT_MIN, currSum = 0;
    int left = 0, right = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (maxSum < currSum)
        {
            maxSum = currSum;
            right = i;
        }
        if (currSum < 0)
        {
            left = i;
            currSum = 0;
        }
    }
    std::cout << "\n Indices are : " << left + 1 << " , " << right << "\n ";
    return maxSum;
}

int main()
{
    std::vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto maxSum = findMaxSum(arr);
    std::cout << "Maximum Subarray sum is: " << maxSum << "\n";
    return 0;
}