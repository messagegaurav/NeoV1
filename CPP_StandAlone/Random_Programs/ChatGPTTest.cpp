#include <iostream>

class DummyClass
{
public:
    // Constructor
    DummyClass() { 
        std::cout << "DummyClass constructor called" << std::endl; 
    }

    // Destructor
    ~DummyClass() { 
        std::cout << "DummyClass destructor called" << std::endl; 
        // Deallocate the memory
        delete data;
    }

    // Move constructor
    DummyClass(DummyClass&& other) { 
        std::cout << "DummyClass move constructor called" << std::endl; 
    }

    // Pointer to some dynamically allocated memory
    int* data = new int[100];
};

int main()
{
    // Create a DummyClass object
    DummyClass dummy;

    // Move the object
    DummyClass dummy2 = std::move(dummy);

    // Print a message
    std::cout << "Hello World!" << std::endl;

    // Return 0
    return 0;
}