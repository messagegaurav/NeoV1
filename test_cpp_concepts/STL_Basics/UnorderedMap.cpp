#include <iostream>
#include <unordered_map>
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
    int getEmpId() const { return empId; }
    string getName() const { return name; }
};

#if SECA
struct hashFunction
{
    size_t operator()(const Employee &emp) const
    {
        return hash<int>()(emp.getEmpId()) ^ (hash<string>()(emp.getName()) << 1);
    }
};

struct equalFunction
{
    bool operator()(const Employee &e1, const Employee &e2) const
    {
        return (e1.getEmpId() == e2.getEmpId() && e1.getName() == e2.getName());
    }
};
#endif
struct EmployeeRecord
{
    unique_ptr<Employee> emp;
    int salary;
    string designation;
};

int main()
{
#if SECA
    unordered_map<string, Employee> salaryMap;

    salaryMap.emplace("Developer", Employee(1, "Alice"));
    salaryMap.emplace("Engineer", Employee(2, "Bob"));
    salaryMap.emplace("Architect", Employee(3, "Charlie"));

    for (const auto &entry : salaryMap)
    {
        cout << "Employee ID: " << entry.second.getEmpId() << ", Name: " << entry.second.getName() << ", Role: " << entry.first << "\n";
    }

    auto it = salaryMap.find("Engineer");
    if (it != salaryMap.end())
    {
        cout << "Found Employee ID 2: " << it->second.getName() << "\n";
    }
    else
    {
        cout << "Employee ID 2 not found\n";
    }
#endif

    unordered_map<string, EmployeeRecord> empRecords;

    empRecords.emplace("Programmer", EmployeeRecord{make_unique<Employee>(1, "David"), 1000, "Programmer"});
    empRecords.emplace("Designer", EmployeeRecord{make_unique<Employee>(2, "Eva"), 2000, "Designer"});
    empRecords.emplace("Manager", EmployeeRecord{make_unique<Employee>(3, "Frank"), 3000, "Manager"});

    for (const auto &entry : empRecords)
    {
        cout << "Employee ID: " << entry.second.emp->getEmpId() << ", Name: " << entry.second.emp->getName() << ", Designation: " << entry.second.designation << "\n";
    }

    auto it = empRecords.find("Designer");
    if (it != empRecords.end())
    {
        cout << "Found Employee: " << it->second.emp->getName() << ", Salary: " << it->second.salary << "\n";
    }
    else
    {
        cout << "Employee not found\n";
    }

    cout << "Load factor: " << empRecords.load_factor() << "\t" << "Bucket count: " << empRecords.bucket_count() << "\t" << "Bucket size: " << empRecords.bucket_size(2) << "\t"
         << "Max load factor: " << empRecords.max_load_factor() << "\t" << "Size: " << empRecords.size() << "\t" << "Max size: " << empRecords.max_size() << "\n";

    return 0;
}