#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
            return -1;

        auto itr = cacheMap[key];
        int value = itr->second;
        cache.erase(itr);
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();
        return value;
    }

    void put(int key, int value)
    {
        if (cacheMap.find(key) != cacheMap.end())
        {
            auto itr = cacheMap[key];
            cache.erase(itr);
        }
        else if (cache.size() == capacity)
        {
            auto itr = cache.back();
            cacheMap.erase(itr.first);
            cache.pop_back();
        }
        cache.push_front({key, value});
        cacheMap[key] = cache.begin();
    }

    void printState() const
    {
        cout << "Cache contents ----" << endl;
        for (const auto &ch : cache)
        {
            cout << "key: " << ch.first << " | value: " << ch.second << endl;
        }
    }
};

int main()
{
    LRUCache LRU(5);
    LRU.put(1, 10);
    LRU.put(2, 20);
    LRU.put(3, 30);
    LRU.put(4, 40);
    LRU.put(5, 50);

    LRU.printState();

    cout << "Get Value for 1: " << LRU.get(1) << endl;

    cout << "Get Value for 2: " << LRU.get(2) << endl;

    LRU.put(6, 60);
    LRU.put(6, 70);
    LRU.put(6, 80);

    LRU.printState();
    return 0;
}