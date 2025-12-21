#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

#define SECA 0
#define SECB 1

class multiply
{
private:
    int num;

public:
    multiply(int n) : num(n)
    {
        cout << "Functor class created with num: " << num << "\n";
    }
    int operator()(int val) const
    {
        return (val * num);
    }
    ~multiply()
    {
        cout << "Functor class destroyed with num: " << num << "\n";
    }
};

class countObj
{
private:
    int countVal;

public:
    countObj() : countVal(0)
    {
        cout << "Count Functor created\n";
    }

    int operator()(int val)
    {
        ++countVal;
        return countVal;
    }

    void showCount() const
    {
        cout << "Current count: " << countVal << "\n";
    }

    ~countObj()
    {
        cout << "Count Functor destroyed with final count: " << countVal << "\n";
    }
};

class Employee
{
private:
    string name;
    int salary;

public:
    Employee(string n, int s) : name(n), salary(s)
    {
        cout << "Employee Created: " << name << "\n";
    }

    int operator()(int raise)
    {
        salary += raise;
        cout << "New salary of " << name << " is: " << salary << "\n";
        return salary;
    }

    void showSalary() const
    {
        cout << "Salary of " << name << " is: " << salary << "\n";
    }

    string getName()
    {
        return name;
    }

    ~Employee()
    {
        cout << "Employee Destroyed: " << name << "\n";
    }
};

class Raise
{
private:
    int raise;

public:
    Raise(int r) : raise(r)
    {
        cout << "Raise Functor created with raise: " << raise << "\n";
    }
    int operator()(unique_ptr<Employee> &emp) const
    {
        return emp->operator()(raise);
    }
    ~Raise()
    {
        cout << "Raise Functor destroyed with raise: " << raise << "\n";
    }
};

int main()
{
#if SECA
    vector<int> vec = {10, 20, 30, 40, 50};
    transform(vec.begin(), vec.end(), vec.begin(), multiply(10));
    for (const auto &val : vec)
    {
        cout << val << " ";
    }
#endif
#if SECA
    vector<int> vec2 = {1, 2, 3, 4, 5};
    countObj c = for_each(vec2.begin(), vec2.end(), countObj());
    c.showCount();
#endif

    vector<unique_ptr<Employee>> empList;
    empList.push_back(make_unique<Employee>("Alice", 50000));
    empList.push_back(make_unique<Employee>("Bob", 60000));
    empList.push_back(make_unique<Employee>("Charlie", 70000));

    for_each(empList.begin(), empList.end(), Raise(1000));

    cout << "\nApplying raises using Employee functor directly:\n";

    for (const auto &emp : empList)
    {
        emp->showSalary();
    }

    for (const auto &emp : empList)
    {
        (*emp)(5000); // Give each employee a raise of 5000
    }

    cout << "\nFinal salaries after direct raises:\n";

    for (const auto &emp : empList)
    {
        emp->showSalary();
    }

    for_each(empList.begin(), empList.end(), [](unique_ptr<Employee> &emp)
             { emp->operator()(2500); });

    // finding if there are more than 60000 salary employees using find_if algorithm
    cout << "\nFinding employees with salary greater than 60000:\n";

    auto it = empList.begin();
    while ((it = find_if(it, empList.end(), [](unique_ptr<Employee> &emp)
                         { return emp->operator()(0) > 60000; })) != empList.end())
    {

        cout << "Employee with salary greater than 60000 found: " << (*it)->getName() << "\n";
        ++it;
    }

    cout << "\n";

    // Sorting employees based on their salary using sort algorithm
    sort(empList.begin(), empList.end(), [](const unique_ptr<Employee> &a, const unique_ptr<Employee> &b)
         { return a->operator()(0) > b->operator()(0); });

    for (const auto &emp : empList)
    {
        emp->showSalary();
    }
    return 0;
}
