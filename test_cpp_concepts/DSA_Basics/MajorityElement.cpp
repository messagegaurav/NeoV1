#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> nums)
{
    unordered_map<int, int> umap;
    for (int num : nums)
    {
        // store count in map against each number
        // return one with the highest count or n/2

        umap[num]++;
        printf("[DEBUG] Number %d: count = %d\n", num, umap[num]);
        if (umap[num] > nums.size() / 2)
        {
            return num;
        }
    }
}

int main()
{
    vector<int> nums = {3, 2, 3, 5, 6, 2, 2, 3, 3, 3, 3};
    printf("[DEBUG] Input numbers: ");
    for (int n : nums)
        printf("%d ", n);
    printf("\n");
    int result = majorityElement(nums);
    cout << "Majority Element: " << result << endl;
    return 0;
}