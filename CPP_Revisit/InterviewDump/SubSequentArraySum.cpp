// IF subsequent elements equals to given target
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void SubSequentArraySum(const vector<int> &vec, int target)
{
    if (vec.empty())
        throw ::runtime_error("Empty data..!!!");

    int len = vec.size();
    unordered_map<int, int> uMap;
    int prefixSum = 0;
    uMap[0] = -1;
    for (int i = 0; i < len; i++)
    {
        prefixSum += vec[i];
        if (uMap.find(prefixSum - target) != uMap.end())
        {
            cout << "Target : " << target << " contains indices from: " << uMap[prefixSum - target] + 1 << " to " << i << endl;
            return;
        }
        uMap[prefixSum] = i;
    }
}

int main()
{
    vector<int> vec = {1, 2, 3, 5, 7, 9};
    int target = 10;
    try
    {
        SubSequentArraySum(vec, target);
    }
    catch (exception &e)
    {
        cout << "Exception encountered: " << e.what() << endl;
    }
    cout << endl;
    return 0;
}