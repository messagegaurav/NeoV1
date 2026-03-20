#include <iostream>
#include <string>
#include <set>
using namespace std;

set<string> allSubSequence(const string &str) {
    set<string> Set;
    if (!str.empty()) {
        int n = str.length();
        for (int mask = 0; mask < (1 << n); mask++) {
            string temp;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    temp += str[i];
            Set.insert(temp);
        }
    }
    return Set;
}

void test(const string &input, int expectedCount) {
    auto result = allSubSequence(input);
    // remove empty string from count
    int count = result.count("") ? result.size() - 1 : result.size();
    bool pass = (expectedCount == -1) || (count == expectedCount);
    cout << (pass ? "PASS" : "FAIL") << " | input: \"" << input << "\" | subsequences: " << count;
    if (expectedCount != -1) cout << " | expected: " << expectedCount;
    cout << "\n";
    if (input.length() <= 3) {
        for (const auto &s : result)
            if (!s.empty()) cout << "   \"" << s << "\"\n";
    }
}

int main() {
    test("", 0);           // empty
    test("A", 1);          // single char -> "A"
    test("AB", 3);         // "A","B","AB"
    test("ABC", 7);        // 2^3 - 1 = 7
    test("AA", -1);        // duplicates -> set deduplicates
    test("ABCD", 15);      // 2^4 - 1 = 15
}
