/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-25 22:58:26
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-26 00:33:40
 */

#include <iostream>
#include <stdio.h>

using namespace std;

// Insertion Sort use it for very small array list
// complexity: if sorted O(n) avergae case O(n2)
void insertionSort(int a[], int n)
{
    int i, value, index;

    for (int i = 1; i < n; i++)
    {
        value = a[i];
        index = i;

        while (index > 0 && a[index - 1] > value)
        {
            a[index] = a[index - 1];
            index = index - 1;
        }
        a[index] = value;
    }
}

// QuickSort begins

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// QuickSort Ends

int main()
{
    int arr[] = {4, 5, -1, 6, -10, 20, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr, len);

    quickSort(arr, 0, len - 1);

    for (auto itr : arr)
    {
        cout << " " << itr;
    }
    cout << "\n\n";
    return 0;
}