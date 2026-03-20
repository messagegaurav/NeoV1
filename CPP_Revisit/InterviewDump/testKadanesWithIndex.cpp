#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> findMaxSumArrayWithIndices(const vector<int> &vec)
{
    if (vec.empty())
        return {-1, -1};

    int start = 0, end = 0, temp_start = 0;
    int len = vec.size();
    int current_max = 0, max_so_far = 0;
    for (int i = 0; i < len; i++)
    {
        if (vec[i] > current_max + vec[i])
        {
            current_max = vec[i];
            temp_start = i;
        }
        else
        {
            current_max += vec[i];
        }

        if (current_max > max_so_far)
        {
            max_so_far = current_max;
            start = temp_start;
            end = i;
        }
    }
    cout << "Max sum is: " << max_so_far << endl;
    return {start, end};
}

int main()
{
    vector<int> vec = {-1, 4, -3, 2, 5, -1, -2, 6};
    auto itr = findMaxSumArrayWithIndices(vec);
    cout << "starts from: " << itr.first << "    ends at: " << itr.second << endl;
    return 0;
}