#include <bits/stdc++.h>
using namespace std;

bool checkBrackets(const string &str) {
    stack<char> staq;
    for (auto &ch : str) {
        if (ch == '[' || ch == '{' || ch == '(') staq.push(ch);
        if ((ch == ']') || (ch == '}') || (ch == ')')) {
            if (staq.empty()) return false;
            else if ((ch == ']' && staq.top() == '[') ||
                     (ch == '}' && staq.top() == '{') ||
                     (ch == ')' && staq.top() == '(')) staq.pop();
            else return false;
        }
    }
    return staq.empty();
}

int main() {
    vector<pair<string, bool>> tests = {
        // valid
        {"", true},
        {"()", true},
        {"[]", true},
        {"{}", true},
        {"()[]{}", true},
        {"{[]}", true},
        {"abc*{ab(*[d])}", true},
        {"({[]})", true},
        // invalid
        {"(", false},
        {")", false},
        {"(]", false},
        {"{[}", false},
        {"([)]", false},
        {"(((",false},
        {")))", false},
        {"{[}", false},
        // with text
        {"hello(world)", true},
        {"hello(world]", false},
    };

    int pass = 0, fail = 0;
    for (auto &[input, expected] : tests) {
        bool result = checkBrackets(input);
        bool ok = result == expected;
        cout << (ok ? "PASS" : "FAIL") << " | input: \"" << input << "\" | expected: " << expected << " | got: " << result << "\n";
        ok ? pass++ : fail++;
    }
    cout << "\n" << pass << " passed, " << fail << " failed\n";
}
