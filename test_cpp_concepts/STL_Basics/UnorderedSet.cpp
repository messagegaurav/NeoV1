#include <iostream>
#include <unordered_set>
#include <memory>

using namespace std;

#define SECA 0
#define SECB 1

class Employee
{
private:
    int empId;
    string name;

public:
    Employee(int id, const string &n) : empId(id), name(n)
    {
        cout << "Employee Created: " << empId << "\n";
    }
    ~Employee()
    {
        cout << "Employee Destroyed: " << empId << "\n";
    }
    int getempId() const { return empId; }
    string getName() const { return name; }

    bool operator==(const Employee &other) const
    {
        return (empId == other.empId && name == other.name);
    }
};

// Hash function for Employee
struct hashFunction
{
    size_t operator()(const Employee &emp) const
    {
        return hash<int>()(emp.getempId()) ^ (hash<string>()(emp.getName()) << 1);
    }
};

int main()
{
    unordered_set<Employee, hashFunction> empSet;
    empSet.emplace(Employee{1, "David"});
    empSet.emplace(Employee{2, "Eva"});
    empSet.emplace(Employee{3, "Frank"});

    for (const auto &entry : empSet)
    {
        cout << "Employee ID: " << entry.getempId() << ", Name: " << entry.getName() << "\n";
    }

    auto it = empSet.find(Employee{2, "Eva"});
    if (it != empSet.end())
    {
        cout << "Found Employee: " << it->getName() << "\n";
    }
    else
    {
        cout << "Employee not found\n";
    }

    if (empSet.count(Employee{3, "Frank"}))
    {
        cout << "Employee with ID 3 exists in the set.\n";
    }
    else
    {
        cout << "Employee with ID 3 does not exist in the set.\n";
    }

    return 0;
}