/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-25 00:39:32
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-03-25 00:52:45
 */

#ifndef __CHRONO__
#define __CHRONO__
#include <chrono>
#include <string>
#include <iostream>

using namespace std;
using namespace chrono;

class Chrono
{
private:
    chrono::_V2::system_clock::time_point start;
    chrono::_V2::system_clock::time_point stop;

public:
    void Start();
    void Stop();
    void Time(string str);
};

void Chrono::Start()
{
    start = chrono::high_resolution_clock::now();
}

void Chrono::Stop()
{
    stop = chrono::high_resolution_clock::now();
}

void Chrono::Time(string str)
{
    if (str == "milli")
        cout << "\n\t Elapsed Time: " << chrono::duration_cast<milliseconds>(stop - start).count() << "  milliseconds !!!" << endl;
    else if (str == "micro")
        cout << "\n\t Elapsed Time: " << chrono::duration_cast<microseconds>(stop - start).count() << "  microseconds !!!" << endl;
    else if (str == "nano")
        cout << "\n\t Elapsed Time: " << chrono::duration_cast<nanoseconds>(stop - start).count() << "  nanoseconds !!!" << endl;
    else
        cout << "\n\t Elapsed Time: " << chrono::duration_cast<seconds>(stop - start).count() << "  seconds !!!" << endl;
}

#endif