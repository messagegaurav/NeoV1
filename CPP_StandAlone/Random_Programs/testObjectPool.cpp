#include <iostream>
#include <vector>

class Object
{
public:
    int id;
    Object(int id) : id(id)
    {
        std::cout << "Object created: " << id << "\n";
    }

    void doWork()
    {
        std::cout << "Object: " << id << "  doing work..!!! \n";
    }
};

class ObjectPool
{
private:
    std::vector<Object *> objects;
    std::vector<bool> available;

public:
    ObjectPool(int size)
    {
        for (int i = 0; i < size; i++)
        {
            objects.push_back(new Object(i));
            available.push_back(true);
        }
    }

    Object *acquire()
    {
        for (int i = 0; i < objects.size(); i++)
        {
            if (available[i])
            {
                available[i] = false;
                std::cout << "Acquired Object: " << objects[i]->id << "\n";
                return objects[i];
            }
        }
        return nullptr;
    }

    void release(Object *obj)
    {
        for (int i = 0; i < objects.size(); i++)
        {
            if (objects[i]->id == obj->id)
            {
                available[i] = true;
                std::cout << "Released Object: " << obj->id << "\n";
                return;
            }
        }
    }

    ~ObjectPool()
    {
        for (auto &obj : objects)
        {
            delete obj;
        }
    }
};

int main()
{
    ObjectPool pool(3);
    Object *obj1 = pool.acquire();
    obj1->doWork();

    Object *obj2 = pool.acquire();
    obj2->doWork();

    pool.release(obj2);
    Object *obj3 = pool.acquire();
    obj3->doWork();

    return 0;
}