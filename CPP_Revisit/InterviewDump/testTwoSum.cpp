#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// vector<pair<int, int>> findTwoSum(const vector<int> &vec, int target) // using only vec
// {
//     vector<pair<int, int>> result;
//     // find = target - vec[i] ;
//     // if found, store it in result
//     // do it in loop

//     int len = vec.size();
//     for (int i = 0; i < len; i++)
//     {
//         int temp = target - vec[i];
//         auto itr = find(vec.begin() + i + 1, vec.end(), temp);
//         if (itr != vec.end())
//         {
//             int dist = distance(vec.begin(), itr);
//             result.push_back({i, dist});
//         }
//     }

//     return result;
// }

vector<pair<int, int>> findTwoSum(const vector<int> &vec, int target) // using hash map
{
    vector<pair<int, int>> result;
    // find = target - vec[i] ;
    // if found, store it in result
    // do it in loop
    unordered_map<int, int> umap;

    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        int temp = target - vec[i];
        // auto itr = find(vec.begin() + i + 1, vec.end(), temp);
        if (umap.find(temp) != umap.end())
        {
            result.push_back({i, umap[temp]});
        }
        umap[vec[i]] = i;
    }
    return result;
}

int main()
{
    vector<int> vec = {-1, -3, 4, 6, 1, 4, 6, -2, 5};
    int target;
    cout << "Enter Target: ";
    cin >> target;
    auto ptr = findTwoSum(vec, target);
    for (const auto &ch : ptr)
    {

        cout << "indices are: " << ch.first << " : " << ch.second << endl;
        cout << endl;
    }

    return 0;
}