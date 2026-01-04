#include <bits/stdc++.h>
using namespace std;

void median(vector<int> nums1, vector<int> nums2)
{
    if (nums1.size() > nums2.size())
    {
        return median(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0;
    int high = x; // size of list A

    while (low <= high)
    {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX)
        {
            // found the correct partitions
            if ((x + y) % 2 == 0)
            {
                double median = (double)(max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2;
                cout << "Median is: " << median << endl;
                return;
            }
            else
            {
                double median = (double)max(maxLeftX, maxLeftY);
                cout << "Median is: " << median << endl;
                return;
            }
        }
        else if (maxLeftX > minRightY)
        {
            // move towards left in nums1
            high = partitionX - 1;
            printf("[DEBUG] Moving left: new high = %d\n", high);
        }
        else
        {
            // move towards right in nums1
            low = partitionX + 1;
            printf("[DEBUG] Moving right: new low = %d\n", low);
        }
    }
}

int main()
{
    vector<int> nums1 = {1, 3, 5, 7};
    vector<int> nums2 = {2, 4, 6, 8, 9, 10};
    printf("[DEBUG] Input nums1: ");
    for (int n : nums1)
        printf("%d ", n);
    printf("\n");
    printf("[DEBUG] Input nums2: ");
    for (int n : nums2)
        printf("%d ", n);
    printf("\n");
    median(nums1, nums2);
    return 0;
}