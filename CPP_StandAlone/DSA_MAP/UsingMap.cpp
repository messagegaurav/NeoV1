/*
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-03-15 17:56:09
 * @Last Modified by:   gaurav
 * @Last Modified time: 2022-03-15 17:56:09
 */

#include <bits/stdc++.h>
using namespace std;

// Function to print frequency of each word
void printFrequency(string str)
{
    map<string, int> M;

    // String for storing the words
    string word = "";

    for (int i = 0; i < str.size(); i++)
    {

        // Check if current character
        // is blank space then it
        // means we have got one word
        if (str[i] == ' ')
        {

            // If the current word
            // is not found then insert
            // current word with frequency 1
            if (M.find(word) == M.end())
            {
                M.insert(make_pair(word, 1));
                word = "";
            }

            // update the frequency
            else
            {
                M[word]++;
                word = "";
            }
        }

        else
            word += str[i];
    }

    // Storing the last word of the string
    if (M.find(word) == M.end())
        M.insert(make_pair(word, 1));

    // Update the frequency
    else
        M[word]++;

    // Traverse the map
    // to print the  frequency
    for (auto &it : M)
    {
        cout << it.first << " - "
             << it.second
             << endl;
    }
}

// Driver Code
int main()
{
    string str = "Geeks For Geeks";

    printFrequency(str);
    return 0;
}
