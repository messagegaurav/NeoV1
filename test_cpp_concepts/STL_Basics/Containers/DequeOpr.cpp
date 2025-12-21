#include <iostream>
#include <deque>
#include <string>
#include <memory>

using namespace std;

// Demo: deque of unique_ptr to Task; ownership is exclusive and automatic.
class Task
{
private:
    int id;
    string name;

public:
    // Construct a Task with id and name (logs creation)
    Task(int i, string n) : id(i), name(n)
    {
        cout << "Task Created: " << name << " with ID: " << id << "\n";
    }

    // Copy constructor (logs copy)
    Task(const Task &other) : id(other.id), name(other.name)
    {
        cout << "Task Copied: " << name << " with ID: " << id << "\n";
    }

    // Move constructor (logs move)
    // NOTE: taking const Task&& prevents moving 'name' efficiently; prefer: Task(Task&&) noexcept
    Task(Task&& other) noexcept : id(other.id), name(move(other.name))
    {
        cout << "Task Moved: " << name << " with ID: " << id << "\n";
    }

    // Copy assignment (logs copy-assign)
    Task &operator=(const Task &other)
    {
        if (this != &other)
        {
            id = other.id;
            name = other.name;
            cout << "Task Assigned: " << name << " with ID: " << id << "\n";
        }
        return *this;
    }

    // Move assignment (logs move-assign)
    Task &operator=(Task &&other) noexcept
    {
        if (this != &other)
        {
            id = other.id;
            name = move(other.name);
            cout << "Task Move Assigned: " << name << " with ID: " << id << "\n";
        }
        return *this;
    }

    // Print task details
    void display() const
    {
        cout << "Task ID: " << id << ", Task Name: " << name << "\n";
    }

    // Logs destruction (unique_ptr ownership ensures this runs exactly once)
    ~Task()
    {
        cout << "Task Destroyed: " << name << " with ID: " << id << "\n";
    }
};

int main()
{
    // Deque holds unique_ptrs; elements are moved, never copied
    deque<unique_ptr<Task>> taskDeQ;

    // Create Tasks and move unique_ptrs into deque (emplace_back with make_unique)
    taskDeQ.emplace_back(make_unique<Task>(1, "Task One"));
    taskDeQ.emplace_back(make_unique<Task>(2, "Task Two"));
    taskDeQ.emplace_front(make_unique<Task>(0, "Task Zero"));

    // Iterate and display tasks
    cout << "\nCurrent Tasks in Deque:\n";
    for (const auto &task : taskDeQ)
    {
        task->display();
    }

    // Remove last element (its unique_ptr is destroyed; Task is freed)
    taskDeQ.pop_back();
    cout << "\nAfter popping back, Current Tasks in Deque:\n";
    for (const auto &task : taskDeQ)
    {
        task->display();
    }

    // Remove first element
    taskDeQ.pop_front();
    cout << "\nAfter popping front, Current Tasks in Deque:\n";
    for (const auto &task : taskDeQ)
    {
        task->display();
    }

    // Add a couple more tasks
    taskDeQ.emplace_back(make_unique<Task>(2, "Task Two"));
    taskDeQ.emplace_front(make_unique<Task>(0, "Task Zero"));

    // Bounds-checked access; throws std::out_of_range if index is invalid
    taskDeQ.at(2)->display();

    return 0;
}