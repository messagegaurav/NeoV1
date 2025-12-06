#include <iostream>
#include <set>
#include <memory>

using namespace std;

#define SECA 0
#define SECB 1

class Tasks
{
private:
    int id;
    string name;

public:
    // Constructor: logs creation
    Tasks(int i, string n) : id(i), name(n)
    {
        cout << "Task Created: " << name << " with ID: " << id << "\n";
    }

    // Destructor: logs destruction
    ~Tasks()
    {
        cout << "Task Destroyed: " << name << "\n";
    }

    // Getters
    int getId() const
    {
        return id;
    }
    string getName() const
    {
        return name;
    }

    // Custom comparator: orders Tasks by id (required for set<Tasks>)
    bool operator<(const Tasks &other) const
    {
        return this->id < other.id;
    }
};

// Custom comparator: compares unique_ptr<Tasks> by dereferencing and comparing ids
struct CompareItems
{
    bool operator()(const unique_ptr<Tasks> &t1, const unique_ptr<Tasks> &t2) const
    {
        return t1->getId() < t2->getId();
    }
};

int main()
{
#if SECA
    // SECA: set of unique_ptr<Tasks> with custom comparator
    set<unique_ptr<Tasks>, CompareItems> taskSet;

    // Insert tasks (ordered by id via CompareItems)
    taskSet.insert(make_unique<Tasks>(3, "Defect Fixing"));
    taskSet.insert(make_unique<Tasks>(1, "Enhancements"));
    taskSet.insert(make_unique<Tasks>(4, "Stories"));
    taskSet.insert(make_unique<Tasks>(2, "Epics"));
    taskSet.insert(make_unique<Tasks>(2, "Wow")); // Duplicate id=2; rejected by set

    cout << "Total tasks in set: " << taskSet.size() << "\n\n";

    // Display all tasks (sorted by id)
    for (const auto &task : taskSet)
    {
        cout << " task: " << task->getId() << " - " << task->getName() << "\n";
    }

    // Find task with id=2 (creates temporary unique_ptr for comparison)
    auto it = taskSet.find(make_unique<Tasks>(2, "Dummy"));
    if (it != taskSet.end())
    {
        cout << "\nFound task with ID 2:\n";
        cout << " task: " << (*it)->getId() << " - " << (*it)->getName() << "\n";
    }
    else
    {
        cout << "\nTask with ID 2 not found.\n";
    }
#endif

#if SECB
    // SECB: set of Tasks objects (by value, uses Tasks::operator<)
    set<Tasks> taskSet;

    // Insert tasks (ordered by id via operator<)
    taskSet.insert(Tasks(3, "Defect Fixing"));
    taskSet.insert(Tasks(1, "Enhancements"));
    taskSet.insert(Tasks(4, "Stories"));
    taskSet.insert(Tasks(2, "Epics"));

    cout << "Total tasks in set: " << taskSet.size() << "\n\n";

    // Display all tasks (sorted by id)
    for (const auto &task : taskSet)
    {
        cout << " task: " << task.getId() << " - " << task.getName() << "\n";
    }

    // Find task with id=2 (creates temporary Tasks for comparison)
    auto it = taskSet.find(Tasks(2, "Dummy"));
    if (it != taskSet.end())
    {
        cout << "\nFound task with ID 2:\n";
        cout << " task: " << it->getId() << " - " << it->getName() << "\n";
    }
    else
    {
        cout << "\nTask with ID 2 not found.\n";
    }
#endif
    return 0;
}