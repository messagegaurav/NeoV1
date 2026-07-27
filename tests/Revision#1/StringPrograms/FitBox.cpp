#include <iostream>
#include <vector>
#include <climits>

/* problem statement: minimum size box to fit the target e.g. input: 6 12   10,15,12,18,9 then output should be 12 */
int main()
{
    std::vector<int> vec;
    int numOfElements, targetSize;
    std::cout << "Enter the no of elements, target size and array of boxes: ";
    std::cin >> numOfElements >> targetSize;
    vec.resize(numOfElements);
    for (int i = 0; i < numOfElements; i++)
        std::cin >> vec[i];

    if ((numOfElements <= 0) || (vec.empty()))
    {
        std::cout << "No elements found !!!" << "\n";
        return -1;
    }

    int i = 0, minBox = INT_MAX;
    while (i < numOfElements)
    {
        if (vec[i] >= targetSize)
        {
            if (minBox >= vec[i])
            {
                minBox = vec[i];
            }
        }
        i++;
    }
    if (minBox == INT_MAX)
    {
        std::cout << "No box found..!!!" << "\n";
    }
    else
    {
        std::cout << "Min size box that fits target: ";
        for (auto &ch : vec)
        {
            if (ch == minBox)
                std::cout << ch << " ";
        }
    }
    vec.clear();
    std::cout << "\n";
    return 0;
}