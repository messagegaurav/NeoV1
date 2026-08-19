/* problem: moving zeroes at the end maintaining the original order */
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {0, 1, 2, 0, 20, 0, 10, 0};

    int n = vec.size();
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (vec[i] != 0)
        {
            vec[pos] = vec[i];
            pos++;
        }
    }
    for (int j = pos; j < n; j++)
    {
        vec[j] = 0;
    }
    for (const auto &i : vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    return 0;
}