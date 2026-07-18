#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int cap) : capacity(cap) {}
    int get(int key);
    void put(int key, int value);
    void printState() const;
};

int LRUCache::get(int key)
{
    if (cacheMap.find(key) == cacheMap.end())
    {
        return -1;
    }

    auto itr = cacheMap[key];
    int value = itr->second;
    cache.erase(itr);
    cache.push_front({key, value});
    return value;
}

void LRUCache::put(int key, int value)
{
    if (cacheMap.find(key) != cacheMap.end())
    {
        auto itr = cacheMap[key];
        cache.erase(itr);
        cacheMap.erase(key);
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

void LRUCache::printState() const
{
    cout << "List elemetns: " << endl;
    for (const auto &node : cache)
    {
        cout << node.first << " : " << node.second << endl;
    }
    cout << endl;
}

int main()
{
    LRUCache lru1(4);
    lru1.put(1, 100);
    lru1.put(2, 200);
    lru1.put(3, 300);
    lru1.put(4, 400);

    cout << "Inserted elemetns: " << endl;
    lru1.printState();

    cout << "after reading element 1 & 2 !!!" << endl;
    cout << "get value at 1: " << lru1.get(1) << endl;
    cout << "get value at 2: " << lru1.get(2) << endl;

    lru1.printState();

    cout << "Max capacity reached !!!" << endl;
    lru1.put(5, 500);

    lru1.printState();

    cout << endl;
    return 0;
}