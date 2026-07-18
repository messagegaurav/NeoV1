// find all the sequence that adds up to 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> find3SumValues(vector<int> &vec)
{
    vector<vector<int>> result;
    vector<int> temp;
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && vec[i] == vec[i - 1])
            continue;
        unordered_map<int, int> umap;
        for (int j = i + 1; j < n; j++)
        {
            int target = -(vec[i] + vec[j]);
            if (umap.find(target) != umap.end())
            {
                result.push_back({vec[i], vec[j], target});
                while (j + 1 < n && vec[j + 1] == vec[j])
                    j++;
            }
            umap[vec[j]] = j;
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {-1, -2, 1, 4, 6, -3, -4, 5, -5};
    auto itr = find3SumValues(vec);
    for (const auto &ch : itr)
    {
        for (const auto &ph : ch)
        {
            cout << " " << ph;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}