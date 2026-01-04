#include <bits/stdc++.h>
using namespace std;

void binarySearch(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid = 0;
    // check if the target lied to the left most limits
    // if yes, keep breaking the list with mid until found

    // if not in the left side, check the same on the right side
    // do the same logic
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            printf("[DEBUG] Target %d found at index %d\n", target, mid);
            return;
        }
        printf("[DEBUG] Left: %d, Mid: %d, Right: %d\n", left, mid, right);
        if (arr[left] <= arr[mid])
        {
            if (target >= arr[left] && target < arr[mid])
            {
                right = mid - 1;
                printf("[DEBUG] New right: %d\n", right);
            }
            else
            {
                left = mid + 1;
                printf("[DEBUG] New left: %d\n", left);
            }
        }
        else
        {
            if (target > arr[mid] && target <= arr[right])
            {
                left = mid + 1;
                printf("[DEBUG] New left: %d\n", left);
            }
            else
            {
                right = mid - 1;
                printf("[DEBUG] New right: %d\n", right);
            }
        }
        printf("[DEBUG] New left: %d\n", left);
    }
}

int main()
{
    vector<int> arr = {8, 2, 1, 0, 5, 4, 7, 8, 10, 9};
    int target = 7;
    printf("[DEBUG] Input array: ");
    for (int n : arr)
        printf("%d ", n);
    printf("\n");
    binarySearch(arr, target);
    return 0;
}