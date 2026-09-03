#include <iostream>
#include <queue>
#include <mutex>
#include <memory>

class Resource
{
public:
    Resource(int id) : id(id)
    {
        std::cout << "Resource: " << id << "    created..!!! \n";
    }

    void use()
    {
        std::cout << "Using resource: " << id << "\n";
    }

    int getId() const
    {
        return id;
    }

private:
    int id;
};

class ObjectPool
{
public:
    std::shared_ptr<Resource> acquire()
    {
        std::lock_guard<std::mutex> lock(mtx);
        if (available.empty())
        {
            auto res = std::make_shared<Resource>(++counter);
            return res;
        }
        else
        {
            auto res = available.front();
            available.pop();
            return res;
        }
    }

    void release(std::shared_ptr<Resource> res)
    {
        std::lock_guard<std::mutex> lock(mtx);
        available.push(res);
        std::cout << " Resource: " << res->getId() << "     released back to pool \n";
    }

private:
    std::mutex mtx;
    int counter = 0;
    std::queue<std::shared_ptr<Resource>> available;
};

int main()
{
    ObjectPool pool;
    auto res1 = pool.acquire();
    res1->use();

    auto res2 = pool.acquire();
    res2->use();

    pool.release(res1);
    pool.release(res2);

    auto res3 = pool.acquire();
    res3->use();

    return 0;
}