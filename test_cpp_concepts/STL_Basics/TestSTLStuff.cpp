#include <bits/stdc++.h>

using namespace std;

class Priority
{
private:
    int priority;
    string task;

public:
    Priority(int p, string t) : priority(p), task(t) {}
    int getPriority() const { return priority; }
    string getTask() const { return task; }
    // bool operator<(const Priority &other) const { return this->priority < other.priority; }
};

// either you go for operator overloading or define a comparator struct
struct comparator
{
    bool operator()(const Priority &p1, const Priority &p2)
    {
        return p1.getPriority() > p2.getPriority();
    }
};

int main()
{
    cout << "Select algorithm to run:\n";
    cout << "1. Remove If (Remove odd numbers from vector)\n";
    cout << "2. Character Frequency in String\n";
    cout << "3. Unique Elements in Sorted Order\n";
    cout << "4. First Duplicate Element Detection\n";
    cout << "5. Time Difference between Map and Unordered_Map\n";
    cout << "6. Lower and Upper Bound Check\n";
    cout << "7. Kth Largest Element using Priority Queue\n";
    cout << "Enter choice (1): ";
    int ch;
    cin >> ch;
    cout << "\n";
    switch (ch)
    {
    case 1:
    {
        // removing the odd numbers from a vector
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        nums.erase(remove_if(nums.begin(), nums.end(), [](int x)
                             { return x % 2 != 0; }),
                   nums.end());
        cout << "Vector after removing odd numbers: ";
        for (const auto &n : nums)
            cout << n << " ";
    }
    case 2:
    {
        // count frequency of characters in a string
        string str = "yabladabladoo";
        map<char, int> freq;
        for (char ch : str)
        {
            freq[ch]++;
        }
        cout << "Character frequencies:\n";
        for (const auto &pair : freq)
        {
            cout << pair.first << ": " << pair.second << "\n";
        }
        break;
    }
    case 3:
    {
        // print unique elements in sorted order
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        set<int> uniqueVals(vals.begin(), vals.end());
        cout << "Unique elements in sorted order: ";
        for (const auto &v : uniqueVals)
            cout << v << " ";
        cout << "\n";
        break;
    }
    case 4:
    {
        // detect first duplicate element
        vector<int> vals = {50, 80, 10, 20, 10, 20, 71, 80, 71, 63, 80};
        unordered_set<int> uniqueVals;
        for (const auto &v : vals)
        {
            if (uniqueVals.count(v))
            {
                cout << "First duplicate element is: " << v << "\n";
                break;
            }
            uniqueVals.insert(v);
        }
        for (const auto &v : uniqueVals)
            cout << v << " ";
        cout << "\n";
        break;
    }

    case 5:
    {
        // finding time difference between map and unordered_map
        map<int, int> mp;
        unordered_map<int, int> ump;
        const int N = 100000;
        // Insertion in map
        auto start = chrono::high_resolution_clock::now();
        for (int i = 0; i < N; ++i)
            mp[i] = i;
        auto end = chrono::high_resolution_clock::now();
        cout << "Time taken for insertion in a map: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";

        // Insertion in unordered_map
        start = chrono::high_resolution_clock::now();
        for (int i = 0; i < N; ++i)
            ump[i] = i;
        end = chrono::high_resolution_clock::now();
        cout << "Time taken for insertion in an unordered_map: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds\n";
        break;
    }

    case 6:
    {
        // checking lower and upper bound
        vector<int> vals = {10, 20, 20, 30, 20, 30, 40, 50};
        int target = 20;
        auto lb = lower_bound(vals.begin(), vals.end(), target);
        auto ub = upper_bound(vals.begin(), vals.end(), target);
        cout << "lower bound is : " << *lb << "\n";
        cout << "upper bound is : " << *ub << "\n";
        cout << "Count of " << target << " is: " << (ub - lb) << "\n";
        cout << "Lower bound of " << target << " is at index: " << distance(vals.begin(), lb) << "\n";
        cout << "Upper bound of " << target << " is at index: " << distance(vals.begin(), ub) << "\n";
        break;
    }

    case 7:
    {
        // priority queue kth largest element
        vector<int> vals = {3, 1, 5, 12, 2, 11, 15};
        int k = 3;
        priority_queue<int> pq(vals.begin(), vals.end());
        while (k--)
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << "\n";

        priority_queue<Priority, vector<Priority>, comparator> taskQueue;
        taskQueue.push(Priority(3, "Low priority task"));
        taskQueue.push(Priority(1, "High priority task"));
        taskQueue.push(Priority(2, "Medium priority task"));

        cout << "Tasks in order of priority:\n";
        while (!taskQueue.empty())
        {
            Priority p = taskQueue.top();
            cout << p.getTask() << " with priority " << p.getPriority() << "\n";
            taskQueue.pop();
        }
        break;
    }
    default:
        cout << "Invalid choice!\n";
    }

    cout << "\n";
    return 0;
}