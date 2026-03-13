#include <iostream>

using namespace std;

int countbits(int num)
{
    int count = 0;
    while (num)
    {
        num = num & (num - 1);
        count++;
    }
    return count;
}

int main()
{

    cout << " no of set bits: " << countbits(10) << endl;
    return 0;
}