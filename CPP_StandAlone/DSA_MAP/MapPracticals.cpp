/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-13 00:02:18
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-13 00:04:43
 */

#include <iostream>
#include <map>
#include <string.h>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;
int main()
{
    auto start = high_resolution_clock::now();

    auto stop = high_resolution_clock::now();

    cout << "\n\n elapsed time: " << duration_cast<microseconds>(stop - start).count();

    cout << "\n\n";
    return 0;
}