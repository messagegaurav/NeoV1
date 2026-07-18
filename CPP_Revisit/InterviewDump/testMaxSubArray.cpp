/* Kadane's algo : finding maximum sub array */
#include <iostream>
#include <vector>

using namespace std;

tuple<int, int, int> findMaxSubArr(const vector<int> &vec)
{
    int len = vec.size();
    // vector<int> result;
    // if (!len)
    //     return result;
    int max_ending_here = vec[0], max_so_far = vec[0];
    int start = 0, tempstart = 0, end = 0;
    for (int i = 1; i < len; i++)
    {
        if (vec[i] > max_ending_here + vec[i])
        {
            tempstart = i;
            max_ending_here = vec[i];
        }
        else
        {
            max_ending_here += vec[i];
        }

        if (max_ending_here > max_so_far)
        {
            max_so_far = max_ending_here;
            start = tempstart;
            end = i;
        }
    }
    return {max_so_far, start, end};
}

int main()
{
    vector<int> vec = {-2, -3, 1, 3, -5, 2, 5, 6, -10};
    auto [maxSum, start, end] = findMaxSubArr(vec);
    for (int i = start; i <= end; i++)
    {
        cout << "[ " << i << "]" << " -> " << vec[i] << endl;
    }
    cout << "Total Sum: " << maxSum << endl;
    // cout << findMaxSubArr(vec);
    cout << endl;
    return 0;
}