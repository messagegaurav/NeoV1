#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    string str = "My name is gaurav awasthi";
    string temp;
    stack<string> st;
    for (const auto &ch : str)
    {
        if (ch != ' ')
        {
            temp += ch;
        }
        else
        {
            st.push(temp);
            st.push(" ");
            temp = "";
        }
    }
    st.push(temp);

    while (!st.empty())
    {
        string ch = st.top();
        st.pop();
        cout << ch;
    }
    cout << "\n";
    return 0;
}