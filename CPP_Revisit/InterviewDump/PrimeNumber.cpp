#include <iostream>

using namespace std;

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
        return true;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
        else
            return true;
    }
    return false;
}

int main()
{
    int limit;
    cout << "enter prime number limit: ";
    cin >> limit;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i))
            cout << " " << i;
    }
    cout << endl;
    return 0;
}
