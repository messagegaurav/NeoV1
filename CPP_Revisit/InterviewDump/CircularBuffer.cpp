#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class CircularBuffer
{
private:
    vector<int> buffer;
    int head, tail, size, capacity;

public:
    CircularBuffer(int cap) : head(0), tail(0), size(0), capacity(cap), buffer(cap, 0) {}

    bool isFull() const { return size == capacity; }
    bool isEmpty() const { return size == 0; }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Buffer is Full, overwrirting the older entry with value: " << val << endl;
            head = (head + 1) % capacity; // overwrite oldest
        }
        else
        {
            size++;
        }
        buffer[tail] = val;
        tail = (tail + 1) % capacity;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Buffer is Empty, Invalid read..!!!" << endl;
            throw ::runtime_error(" Buffer Empty..!!!");
        }
        int val = buffer[head];
        head = (head + 1) % capacity;
        size--;
        return val;
    }

    void printState() const
    {
        cout << "Buffer contents: " << endl;
        for (int i = 0; i < size; i++)
        {
            int id = (head + i) % capacity;
            cout << buffer[id] << " ";
        }
        cout << endl;
    }
};

int main()
{
    CircularBuffer buffer(5);
    buffer.push(10);
    buffer.push(20);
    buffer.push(30);
    buffer.push(40);
    buffer.push(50);

    buffer.printState();

    // overwrite case
    buffer.push(60);
    buffer.printState();

    try
    {

        cout << " Val: " << buffer.pop() << endl;
        cout << " Val: " << buffer.pop() << endl;
        cout << " Val: " << buffer.pop() << endl;
        cout << " Val: " << buffer.pop() << endl;
        cout << " Val: " << buffer.pop() << endl;

        buffer.printState();
        cout << " Val: " << buffer.pop() << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Caught exception: " << e.what() << endl;
    }
    buffer.push(70);
    buffer.printState();

    return 0;
}