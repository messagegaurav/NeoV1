/*find longest consecutive sequence
e.g. if its 100, 4, 200, 2, 3, 1 then ouput should be length 4 (1, 2, 3, 4)*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/* first approach that works with positive numbers */
int findLCS(const vector<int> &vec)
{
    // remember when we have to find something,
    // always focus on hashmap coz of O(1) lookup speed
    unordered_map<int, int> umap;
    int len = vec.size();
    int currlen = 1, maxlen = 1;
    for (int i = 0; i < len; i++)
        umap[vec[i]] = i;
    unordered_set<int> uset;
    for (int i = 0; i < len; i++)
    {
        int num = vec[i];
        while (umap.find(num + 1) != umap.end())
        {
            if (uset.find(num) != uset.end())
                break;
            num += 1;
        }

        while (umap.find(num - 1) != umap.end())
        {
            if (uset.find(num) != uset.end())
                break;
            currlen++;
            maxlen = max(maxlen, currlen);
            uset.insert(num);
            num -= 1;
        }
        currlen = 1;
    }
    return maxlen;
}

int findLCSSmartly(const vector<int> &vec)
{
    if (!vec.size())
        return 0;

    unordered_set<int> uset(vec.begin(), vec.end()); // need pre-populated set
    int currlen = 1, maxlen = 1;
    for (const auto &i : vec)
    {
        int num = i;
        currlen = 1;
        if (uset.find(num - 1) == uset.end())
        {
            while (uset.find(num + 1) != uset.end())
            {
                currlen++;
                num += 1;
            }
            maxlen = max(maxlen, currlen);
        }
    }
    return maxlen;
}

int main()
{
    // vector<int> vec = {100, 4, 200, 3, 2, 1};
    vector<int> vec = {1, 3, 5, 2, 4, 100, 200};
    // vector<int> vec = {
    //     5, 6, 7, 100, 101};

    // int result = findLCS(vec);
    int result = findLCSSmartly(vec);
    cout << "result: " << result << endl;
    cout << endl;
    return 0;
}