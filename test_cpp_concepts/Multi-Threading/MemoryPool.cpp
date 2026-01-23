#include <vector>
#include <iostream>
#include <cstring>
#include <mutex>
#include <set>

class MemoryPool
{
private:
    std::vector<void *> freeBlocks;
    std::set<void *> allocatedBlocks; // Track allocated blocks
    char *pool;
    size_t blockSize;
    size_t blockCount;
    std::mutex poolMutex; // Thread safety

public:
    MemoryPool(size_t bSize, size_t bCount) : blockSize(bSize), blockCount(bCount)
    {
        pool = new char[blockSize * blockCount];
        for (size_t i = 0; i < blockCount; ++i)
        {
            freeBlocks.push_back(pool + i * blockSize);
        }
    }

    ~MemoryPool()
    {
        if (!allocatedBlocks.empty())
        {
            std::cout << "Warning: " << allocatedBlocks.size() << " blocks still allocated!\n";
        }
        delete[] pool;
    }

    void *allocate()
    {
        std::lock_guard<std::mutex> lock(poolMutex);
        if (!freeBlocks.empty())
        {
            void *block = freeBlocks.back();
            freeBlocks.pop_back();
            allocatedBlocks.insert(block); // Track allocation
            return block;
        }
        else
        {
            std::cout << "No free blocks available" << std::endl;
            return nullptr;
        }
    }

    void deallocate(void *block) // Fixed return type
    {
        if (block == nullptr)
            return;

        std::lock_guard<std::mutex> lock(poolMutex);

        // Validate block belongs to this pool
        if (block < pool || block >= pool + (blockSize * blockCount))
        {
            std::cout << "Error: Block not from this pool!\n";
            return;
        }

        // Check if block is actually allocated
        if (allocatedBlocks.find(block) == allocatedBlocks.end())
        {
            std::cout << "Error: Double free or invalid block!\n";
            return;
        }

        allocatedBlocks.erase(block);
        freeBlocks.push_back(block);
    }
};

int main()
{
    MemoryPool pool(1024, 10);

    void *block1 = pool.allocate();
    void *block2 = pool.allocate();
    void *block3 = pool.allocate();

    strcpy(static_cast<char *>(block1), "Hello");
    strcpy(static_cast<char *>(block2), "World");
    strcpy(static_cast<char *>(block3), "!");

    std::cout << static_cast<char *>(block1) << std::endl;
    std::cout << static_cast<char *>(block2) << std::endl;
    std::cout << static_cast<char *>(block3) << std::endl;

    pool.deallocate(block1);
    pool.deallocate(block2);
    pool.deallocate(block3);

    return 0;
}