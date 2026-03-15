// Any combination (not neccessarily contiguous) of element that totals to target
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findAnySumTarget(vector<int> &vec, int target, int start, vector<int> &current, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(current);
        return;
    }
    for (int i = start; i < vec.size(); i++)
    {
        if (i > start && vec[i] == vec[i - 1])
            continue; // to skip duplicates
        if (vec[i] <= target)
        {
            current.push_back(i);
            findAnySumTarget(vec, target - vec[i], i + 1, current, result);
            current.pop_back();
        }
    }
}

int main()
{
    vector<int> vec = {4, 5, 2, 1, 7, 9, 6};
    int target = 12;
    vector<vector<int>> result;
    vector<int> current;
    findAnySumTarget(vec, target, 0, current, result);
    for (const auto &ch : result)
    {
        cout << "Indices: " << endl;
        for (const auto &val : ch)
        {
            cout << " " << val;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}