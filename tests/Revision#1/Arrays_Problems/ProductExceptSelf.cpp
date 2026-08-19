#include <iostream>
#include <vector>

std::vector<int> productOfArray(const std::vector<int> &arr)
{
    if (arr.empty())
    {
        std::cout << "Input array is empty ... !!!" << "\n";
    }
    int n = arr.size();
    std::vector<int> result(n);

    int prefix = 1;
    std::cout << "Prefix array: " << "\n";
    for (int i = 0; i < n; i++)
    {
        result[i] = prefix;
        prefix *= arr[i];
        std::cout << result[i] << " ";
    }
    std::cout << "\n Suffix Array: " << "\n";
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= suffix;
        suffix *= arr[i];
        std::cout << result[i] << " ";
    }
    return result;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    auto result = productOfArray(arr);
    std::cout << "\n final output is: " << "\n";
    for (const auto &itr : result)
    {
        std::cout << itr << " ";
    }
    std::cout << "\n";
    return 0;
}
