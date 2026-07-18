#include <iostream>
#include <vector>

using namespace std;

void findPattern(const vector<int> &vec, int target, int start, vector<int> &path, vector<vector<int>> &result)
{
    if (target == 0)
    {
        result.push_back(path);
        return;
    }
    int len = vec.size();
    for (int i = start; i < len; i++)
    {
        // if(vec[i] <= target) // only do pruning if numbers are positive, else avoid it
        path.push_back(i);
        findPattern(vec, target - vec[i], i + 1, path, result);
        path.pop_back();
    }
}

vector<vector<int>> findNIndicesForSumTarget(const auto &vec, int target)
{
    vector<vector<int>> result;
    vector<int> path;
    findPattern(vec, target, 0, path, result);
    return result;
}

int main()
{
    vector<int> vec = {-1, -3, 4, 6, 1, 4, 6, -2, 5};
    int target;
    cout << "Enter Target: ";
    cin >> target;
    auto result = findNIndicesForSumTarget(vec, target);

    cout << "Indices with values... " << endl;
    for (const auto &ch : result)
    {
        for (const auto &ph : ch)
        {
            cout << "[" << ph << "]" << " -> " << vec[ph];
        }
        cout << endl;
    }
    return 0;
}