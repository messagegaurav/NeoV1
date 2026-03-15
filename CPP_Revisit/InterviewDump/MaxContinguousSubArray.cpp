// KADANE's Algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxSubArraySum(const vector<int> &vec)
{
    int len = vec.size();
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < len; i++)
    {
        max_ending_here = max(vec[i], max_ending_here + vec[i]);
        max_so_far = max(max_so_far, max_ending_here);
        cout << "Step " << i << ": "
             << "max_ending_here=" << max_ending_here
             << ", max_so_far=" << max_so_far << endl;
    }
    return max_so_far;
}

int main()
{
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    int result = findMaxSubArraySum(vec);
    cout << "\n\n Max Sum: " << result;
    cout << endl;
    return 0;
}