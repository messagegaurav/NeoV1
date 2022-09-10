/*
 * @Author: gauravawasthi@outlook.com 
 * @Date: 2022-09-10 14:10:34 
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-09-11 01:02:39
 */

#include "mychrono.h"
#include <iostream>
#include <string>
#include <memory.h>
#include <sstream> 
#include <bits/stdc++.h>
#include <vector>

using namespace std; 

void GetLine()
{
    string lines;     
    vector<string> myVec;
    
    while (getline(cin, lines))
    {
        myVec.push_back(lines);
    }

    for (auto i : myVec)
    cout<<"target lines:    "<<i<<"\n";
    myVec.clear();
}

int main (int argc, char* argv[])
{
    GetLine();
    return 0;
}