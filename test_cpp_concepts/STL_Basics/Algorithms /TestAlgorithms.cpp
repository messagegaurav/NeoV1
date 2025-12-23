#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iterator>
#include <list>

using namespace std;

// People class for sort/stable_sort demo
class People
{
    int age;
    string name;

public:
    People(int a, string n) : age(a), name(n) {}
    string getName() const { return name; }
    int getAge() const { return age; }
    bool operator<(const People &other) const { return this->age < other.age; }
};

#include <unordered_map>

using namespace std;

int main()
{
    cout << "Select algorithm to run:\n";
    cout << "1. Find & Binary Search\n";
    cout << "2. Count & Count_if\n";
    cout << "3. Sort & Stable Sort (People)\n";
    cout << "4. String Reverse\n";
    cout << "5. Max/Min Element (Strings)\n";
    cout << "6. Partial Sort (Top 5)\n";
    cout << "7. Nth Element (4th smallest/greatest)\n";
    cout << "8. Lower/Upper Bound\n";
    cout << "9. Equal Range\n";
    cout << "10. Accumulate & Inner Product\n";
    cout << "11. Rotate & Reverse Vector\n";
    cout << "12. Remove Duplicates\n";
    cout << "13. Remove/Pop Last Element\n";
    cout << "14. Map/Unordered Map Remove Last\n";
    cout << "15. Erase duplicates from the list\n";
    cout << "16. Copy algo \n";
    cout << "17. Iota algo \n";
    cout << "18. Missing Elements (Set Difference)\n";
    cout << "19. Common Elements (Set Intersection)\n";
    cout << "Enter choice (1-19): ";
    int choice;
    cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
    {
        vector<int> num = {5, 6, 1, 2, 4, 3, 0};
        auto it = find(num.begin(), num.end(), 4);
        if (it != num.end())
            cout << "Element 4 found at position: " << distance(num.begin(), it) << "\n";
        else
            cout << "Element 4 not found\n";
        sort(num.begin(), num.end());
        bool its = binary_search(num.begin(), num.end(), 4);
        if (its)
            cout << "Element 4 found using binary search : " << distance(num.begin(), lower_bound(num.begin(), num.end(), 4)) << "\n";
        else
            cout << "Element 4 not found using binary search\n";
        break;
    }
    case 2:
    {
        vector<int> num = {5, 6, 4, 2, 4, 3, 4};
        int cnt = count(num.begin(), num.end(), 4);
        cout << "Count of element 4 is: " << cnt << "\n";
        int cntIf = count_if(num.begin(), num.end(), [](int val)
                             { return val % 2 == 0; });
        cout << "Count of even numbers is: " << cntIf << "\n";
        break;
    }
    case 3:
    {
        cout << "using normal sort :\n";
        vector<People> ppl = {
            People(25, "John"), People(30, "Alice"), People(22, "Bob"), People(30, "Charlie"), People(25, "David")};
        sort(ppl.begin(), ppl.end());
        for (const auto &p : ppl)
            cout << p.getName() << " : " << p.getAge() << "\n";
        stable_sort(ppl.begin(), ppl.end());
        cout << "\nusing stable sort :\n";
        for (const auto &p : ppl)
            cout << p.getName() << " : " << p.getAge() << "\n";
        break;
    }
    case 4:
    {
        string name = "Gaurav is a good boy";
        // reverse(name.begin(), name.end());
        // cout << "Reversed string: " << name << "\n";

        // Reversing only the positions and not the words
        istringstream iss(name);
        vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};

        reverse(words.begin(), words.end());

        ostringstream oss;
        if (!words.empty())
        {
            copy(words.begin(), words.end() - 1, ostream_iterator<string>(oss, " "));
            oss << words.back();
        }

        cout << "Reversed words string: " << oss.str() << "\n";
        break;
    }
    case 5:
    {
        vector<string> numbers = {"alice", "bob", "charlie", "david"};
        auto maxval = max_element(numbers.begin(), numbers.end());
        cout << "Maximum element in numbers: " << *maxval << "\n";
        auto minval = min_element(numbers.begin(), numbers.end());
        cout << "Minimum element in numbers: " << *minval << "\n";
        break;
    }
    case 6:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        partial_sort(vals.begin(), vals.begin() + 5, vals.end());
        cout << "First 5 sorted elements: ";
        for (int i = 0; i < 5; ++i)
            cout << vals[i] << " ";
        cout << "\n";
        break;
    }
    case 7:
    {
        vector<int> myVec = {60, 70, 10, 30, 20, 8, 5, 9};
        nth_element(myVec.begin(), myVec.begin() + 3, myVec.end());
        cout << "4th smallest element is: " << myVec[3] << "\n";
        vector<int> myVec2 = {60, 70, 10, 30, 20, 8, 5, 9};
        nth_element(myVec2.begin(), myVec2.begin() + 3, myVec2.end(), greater<int>());
        int fourth_greatest = myVec2[3];
        cout << "4th greatest element is: " << fourth_greatest << "\n";
        if (fourth_greatest == 20)
            cout << "4th greatest element is 20!" << endl;
        else
            cout << "4th greatest element is not 20." << endl;
        break;
    }
    case 8:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        sort(vals.begin(), vals.end());
        auto lb = lower_bound(vals.begin(), vals.end(), 20);
        auto ub = upper_bound(vals.begin(), vals.end(), 20);
        int count = ub - lb;
        cout << "Count of element 20 is: " << count << "\n";
        cout << "lb : " << (lb != vals.end() ? to_string(*lb) : "n/a") << ", ub : " << (ub != vals.end() ? to_string(*ub) : "n/a") << "\n";
        cout << "Lower bound of 20 is at position: " << distance(vals.begin(), lb) << "\n";
        cout << "Upper bound of 20 is at position: " << distance(vals.begin(), ub) << "\n";
        break;
    }
    case 9:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        sort(vals.begin(), vals.end());
        auto eqr = equal_range(vals.begin(), vals.end(), 8);
        if (eqr.first != vals.end())
            cout << "Equal range of 8 is: [" << *eqr.first << ", " << (eqr.second != vals.end() ? to_string(*eqr.second) : "end") << ")\n";
        else
            cout << "No equal range for 8\n";
        break;
    }
    case 10:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        auto accm = accumulate(vals.begin(), vals.end(), 0);
        cout << "Accumulated sum of vals: " << accm << "\n";
        auto ip = inner_product(vals.begin(), vals.end(), vals.begin(), 0);
        cout << "Inner product of vals with itself: " << ip << "\n";
        break;
    }
    case 11:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        rotate(vals.begin(), vals.begin() + 3, vals.end());
        cout << "Vector after rotation: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";
        reverse(vals.begin(), vals.end());
        cout << "Vector after reversing: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";
        break;
    }
    case 12:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        sort(vals.begin(), vals.end());
        auto last = unique(vals.begin(), vals.end());
        vals.erase(last, vals.end());
        cout << "Vector after removing duplicates: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";
        break;
    }
    case 13:
    {
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        vals.erase(remove(vals.begin(), vals.end(), 80), vals.end());
        if (!vals.empty())
            vals.pop_back();
        cout << "Vector after removing last element: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";
        break;
    }
    case 14:
    {
        map<int, string> mp = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
        if (!mp.empty())
            mp.erase(prev(mp.end()));
        cout << "Map after removing last element: ";
        for (const auto &p : mp)
            cout << p.first << ":" << p.second << " ";
        cout << "\n";
        unordered_map<int, string> ump = {{1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"}};
        if (!ump.empty())
            ump.erase(ump.begin());
        cout << "Unordered Map after removing an element: ";
        for (const auto &p : ump)
            cout << p.first << ":" << p.second << " ";
        cout << "\n";
        break;
    }

    case 15:
    {
        list<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        vals.sort();   // Sort the list first
        vals.unique(); // Remove duplicates
        cout << "List after erasing duplicates: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";

        vector<int> vec = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        cout << "Vector after erasing duplicates: ";
        for (const auto &v : vec)
            cout << v << " ";
        cout << "\n";
        break;
    }

    case 16:
    {
        vector<int> source = {1, 2, 3, 4, 5};
        vector<int> destination(source.size());
        copy(source.begin(), source.end(), destination.begin());
        cout << "Destination vector after copy: ";
        for (const auto &v : destination)
            cout << v << " ";
        cout << "\n";
        break;
    }

    case 17:
    {
        // using iota
        vector<int> vals(10);
        iota(vals.begin(), vals.end(), 1); // Fill with values starting from 1
        cout << "Vector after iota: ";
        for (const auto &v : vals)
            cout << v << " ";
        cout << "\n";
        break;
    }

    case 18:
    {
        // finding missing elements
        vector<string> vals = {"Bob", "Alpha", "Charlie", "Tom", "Muse", "Fuse"};
        vector<string> fullRange = {"Alpha", "Bob", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet", "Kilo", "Lima", "Mike", "Muse", "November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra", "Tom", "Uniform", "Victor", "Whiskey", "X-ray", "Yankee", "Zulu"};
        sort(vals.begin(), vals.end());
        sort(fullRange.begin(), fullRange.end());
        vector<string> missingElements;
        set_difference(fullRange.begin(), fullRange.end(), vals.begin(), vals.end(), back_inserter(missingElements));
        cout << "Missing elements: ";
        for (const auto &v : missingElements)
            cout << v << " ";
        cout << "\n";
        break;
    }

    case 19:
    {
        // common data in two containers
        vector<string> vals1 = {"Bob", "Alpha", "Charlie", "Tom", "Muse", "Fuse"};
        vector<string> vals2 = {"Alpha", "Delta", "Charlie", "Echo", "Muse", "Golf"};
        sort(vals1.begin(), vals1.end());
        sort(vals2.begin(), vals2.end());
        vector<string> commonElements;
        set_intersection(vals1.begin(), vals1.end(), vals2.begin(), vals2.end(), back_inserter(commonElements));
        cout << "Common elements: ";
        for (const auto &v : commonElements)
            cout << v << " ";
        cout << "\n";
        break;
    }
    default:
        cout << "Invalid choice.\n";
    }
    return 0;
}