/* prob: return product of all numbers except self e.g. {1,2,3,4} -> {24, 12, 8, 6}*/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

/* first approach came to mind*/
vector<int> findArrProduct(const vector<int> &vec)
{
    // take a set
    // while loop
    // num = vec[i];
    // for (vec) { if set.find(num) skip else *}
    //
    unordered_set<int> uset;
    int len = vec.size();
    vector<int> result;
    for (const auto &i : vec)
    {
        uset.insert(i);
        int tempvar = 1;
        int temp = 0;
        while (temp < len)
        {
            if (uset.find(vec[temp]) == uset.end())
            {
                tempvar = tempvar * vec[temp];
            }
            temp++;
        }
        result.push_back(tempvar);
        uset.clear();
    }
    return result;
}

/* prefix and suffix approach .. thats cool ;) */

vector<int> findArrProductSmartly(const vector<int> &vec)
{
    int len = (int)vec.size();
    vector<int> result(len, 1);

    int prefix = 1;
    for (int i = 0; i < len; i++)
    {
        result[i] = prefix;
        prefix *= vec[i];
    }

    int suffix = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        result[i] *= suffix;
        suffix *= vec[i];
    }
    return result;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};
    // auto itr = findArrProduct(vec);
    auto itr = findArrProductSmartly(vec);
    for (const auto &ch : itr)
    {
        cout << ch << " ";
    }
    cout << endl;
    return 0;
}