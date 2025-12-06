#include <iostream>
#include <memory>
#include <queue>

using namespace std;

class Task
{
private:
    string name;
    int priority;

public:
    Task(string n, int p) : name(n), priority(p)
    {
        cout << "Task Created: " << name << " with Priority: " << priority << "\n";
    }
    ~Task()
    {
        cout << "Task Destroyed: " << name << "\n";
    }
    void display() const
    {
        cout << "Task Name: " << name << ", Priority: " << priority << "\n";
    }
    int getPriority() const
    {
        return priority;
    }
    string getName() const
    {
        return name;
    }
};

struct compareTask
{
    bool operator()(const unique_ptr<Task> &t1, const unique_ptr<Task> &t2)
    {
        return t1->getPriority() < t2->getPriority();
    }
};

int main()
{
    priority_queue<unique_ptr<Task>, vector<unique_ptr<Task>>, compareTask> pQueue;
    pQueue.push(make_unique<Task>("Task 1", 3));
    pQueue.push(make_unique<Task>("Task 2", 5));
    pQueue.push(make_unique<Task>("Task 3", 1));
    pQueue.push(make_unique<Task>("Task 4", 4));
    pQueue.push(make_unique<Task>("Task 5", 2));

    cout << "Total tasks in priority queue: " << pQueue.size() << "\n\n";
    int len = pQueue.size();
    while (pQueue.empty() == false)
    {
        cout << "Highest priority task:\n";
        pQueue.top()->display();
        pQueue.pop();
    }
    return 0;
}