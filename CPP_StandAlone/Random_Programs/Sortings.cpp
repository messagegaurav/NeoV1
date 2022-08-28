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
// complexity: if sorted O(n) avergae case O(n2) worst case O(n2)
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
// best case: O(n log n) average case: O(n log n) and worst case: O(n2)
// Pros: in space sorting algo
// worst case: O(n2)
// works good on arrays due to nice exhibiting of indexes
// tail recursive

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

// mergeSort begins
// best case: O(n log n) average case: O(n log n) and worst case: O(n log n)
// not in-place sorting algo
// usually applied on slow and big data's list

void mergeHalves(int arr[], int leftIndex, int mid, int rightIndex)
{

    int i, j, k;
    int left = (mid - leftIndex) + 1;
    int right = rightIndex - mid;

    int leftArr[left];
    int rightArr[right];

    for (i = 0; i < left; i++)
    {
        leftArr[i] = arr[leftIndex + i];
    }

    for (j = 0; j < right; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = leftIndex;
    while ((i < left) && (j < right))
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // extra element left in left sub array
    while (i < left)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // extra element left in right sub array
    while (j < right)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex)
    {
        int mid = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSort(a, leftIndex, mid);
        mergeSort(a, mid + 1, rightIndex);
        mergeHalves(a, leftIndex, mid, rightIndex);
    }
}

int main()
{
    int arr[] = {4, 5, -1, 6, -10, 20, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    // insertionSort(arr, len);

    // quickSort(arr, 0, len - 1);

    mergeSort(arr, 0, len - 1);

    for (auto itr : arr)
    {
        cout << " " << itr;
    }
    cout << "\n\n";
    return 0;
}