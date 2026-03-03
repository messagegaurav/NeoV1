#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string checkLCP(const string &str, const string &str1, const string &str2)
{
    string temp;

    // int minlen = (lenStr < lenStr1) ? ((lenStr < lenStr2) ? lenStr : lenStr2) : ((lenStr1 < lenStr2) ? lenStr1 : lenStr2);
    int minlen = min({str.length(), str1.length(), str2.length()});

    for (int i = 0; i < minlen; i++)
    {
        if ((str[i] == str1[i]) && (str[i] == str2[i]))
        {
            temp += str[i];
        }
        else
            break;
    }
    return temp;
}

// string useVector(const vector<string> &vec)
// {
//     if (vec.empty())
//         return "";
//     else
//         for (int i = 0; i < vec[0].length(); i++)
//         {
//             for (auto &ch : vec)
//             {
//                 if (i >= ch.length() || ch[i] != vec[0][i])
//                 {
//                     return vec[0].substr(0, i);
//                 }
//             }
//         }
//     return vec[0];
// }

string useVector(const vector<string> &vecString)
{
    if (vecString.empty())
        return "";
    for (int i = 0; i < vecString[0].length(); i++)
    {
        for (auto &ch : vecString)
        {
            if (i >= ch.length() || ch[i] != vecString[0][i])
            {
                return vecString[0].substr(0, i);
            }
        }
    }
    return vecString[0];
}

int main()
{
    string str2 = "flowerland";
    string str = "flower";
    string str1 = "flow";

    vector<string> vecString = {str, str1, str2};

    // auto temp = checkLCP(str, str1, str2);
    auto temp = useVector(vecString);
    cout << "\nfinal string: " << temp << endl;
    return 0;
}