#include <iostream>
#include <map>
#include <memory>

using namespace std;

#define SECA 0
#define SECB 1

class Employee
{
private:
    unsigned long int Mobile;
    string name;

public:
    Employee(unsigned long int m, const string &n) : Mobile(m), name(n)
    {
        cout << "Employee Created: " << Mobile << "\n";
    }
    ~Employee()
    {
        cout << "Employee Destroyed: " << Mobile << "\n";
    }
    unsigned long int getMobile() const { return Mobile; }
    string getName() const { return name; }
};

// Custom comparator for unique_ptr<Employee> (ordered by mobile descending)
struct EmployeeComparator
{
    bool operator()(const unique_ptr<Employee> &a, const unique_ptr<Employee> &b) const
    {
        return a->getMobile() > b->getMobile(); // descending order by mobile
    }
};

class Manager
{
private:
    // Key: unique_ptr<Employee>, Value: string (employee name)
    map<unique_ptr<Employee>, string, EmployeeComparator> emp;

public:
    // Add employee: create unique_ptr and store with name as value
    void addEmployee(const string &name, unsigned long int mobile)
    {
        emp.emplace(make_unique<Employee>(mobile, name), name);
    }

    // Remove employee by mobile number
    void removeEmployee(unsigned long int mobile)
    {
        // Find employee with matching mobile number
        auto it = emp.begin();
        while (it != emp.end())
        {
            if (it->first->getMobile() == mobile)
            {
                cout << "Employee with ID " << mobile << " removed.\n";
                emp.erase(it);
                return;
            }
            ++it;
        }
        cout << "Employee with ID " << mobile << " not found.\n";
    }

    // Display all employees
    void displayEmployees() const
    {
        for (const auto &pair : emp)
        {
            cout << "Employee Mobile: " << pair.first->getMobile()
                 << ", Name: " << pair.second << "\n";
        }
    }

    // Find employee by name and return pointer to Employee
    Employee *findEmployee(const string &empName) const
    {
        for (const auto &pair : emp)
        {
            if (pair.second == empName)
            {
                return pair.first.get();
            }
        }
        return nullptr;
    }
};

int main()
{
#if SECA
    map<int, string> tasks;
    tasks[0] = "Enhancements";
    tasks.insert({1, "Code Review"});
    tasks.emplace(2, "Documentation");
    tasks.emplace(3, "Documentation"); // duplicate key, will be ignored

    for (const auto &task : tasks)
    {
        cout << "Task ID: " << task.first << ", Task Name: " << task.second << "\n";
    }

    auto it = tasks.find(2);
    if (it != tasks.end())
    {
        cout << "Found Task ID 2: " << it->second << "\n";
        tasks.erase(it);
        cout << "Task ID 2 erased\n";
    }
    else
    {
        cout << "Task ID 2 not found\n";
    }

    if (tasks.count(3))
    {
        cout << "Task ID 3 exists with name: " << tasks[3] << "\n";
    }
    else
    {
        cout << "Task ID 3 does not exist\n";
    }

    cout << "size of map: " << tasks.size() << "\n";
    tasks.clear();
    cout << "size of map after clear: " << tasks.size() << "\n";
#endif

#if SECB
    unique_ptr<Manager> mgr = make_unique<Manager>();
    mgr->addEmployee("Alice", 9986091157);
    mgr->addEmployee("Bob", 9986090098);
    mgr->addEmployee("Charlie", 9986001001);

    cout << "\nAll Employees:\n";
    mgr->displayEmployees();

    Employee *emp = mgr->findEmployee("Bob");
    if (emp)
    {
        cout << "\nFound Employee: " << emp->getName() << " with Mobile: " << emp->getMobile() << "\n";
    }

    mgr->removeEmployee(9986001001);

    cout << "\nEmployees after removal:\n";
    mgr->displayEmployees();
#endif
    return 0;
}
