#include <iostream>
#include <memory>
#include <string>

// Receiver: performs the actual work (BACnet write)
class cBacnetComm
{
public:
    void writeData(const std::string &devId, const std::string &prop, const std::string &value)
    {
        std::cout << "Writing to device " << devId << " property " << prop << " value " << value << std::endl;
    }
    ~cBacnetComm()
    {
        std::cout << "cBacnetComm Destructor Called" << std::endl;
    }
};

// Command interface: executable action
class cControllerInterface
{
public:
    virtual void executeCommand() = 0;
    virtual ~cControllerInterface() = default;
};

// Concrete command: Start AHU
// Shared receiver so multiple commands can target same device
class cStartAHU : public cControllerInterface
{
private:
    std::shared_ptr<cBacnetComm> mBacnet; // shared ownership of receiver
    std::string devId;                    // target device id

public:
    cStartAHU(std::shared_ptr<cBacnetComm> bacnet, const std::string &id) : mBacnet(std::move(bacnet)), devId(id) {}
    void executeCommand() override
    {
        mBacnet->writeData(devId, "Start", "On");
    }
    ~cStartAHU() override
    {
        std::cout << "cStartAHU Destructor Called" << std::endl;
    }
};

// Concrete command: Stop AHU
class cStopAHU : public cControllerInterface
{
private:
    std::shared_ptr<cBacnetComm> mBacnet; // shared receiver
    std::string devId;

public:
    cStopAHU(std::shared_ptr<cBacnetComm> bacnet, const std::string &id) : mBacnet(std::move(bacnet)), devId(id) {}
    void executeCommand() override
    {
        mBacnet->writeData(devId, "Stop", "Off");
    }
    ~cStopAHU() override
    {
        std::cout << "cStopAHU Destructor Called" << std::endl;
    }
};

// Invoker: holds a command and triggers it
class cOperator
{
private:
    std::unique_ptr<cControllerInterface> mCommand; // owns command

public:
    explicit cOperator(std::unique_ptr<cControllerInterface> command) : mCommand(std::move(command)) {}
    void invoke()
    {
        mCommand->executeCommand();
    }

    ~cOperator()
    {
        std::cout << "cOperator Destructor Called" << std::endl;
    }
};

int main()
{
    // Client wiring: share one receiver across commands
    auto bacnetInterface = std::make_shared<cBacnetComm>();
    auto startAHU = std::make_unique<cStartAHU>(bacnetInterface, "101");
    auto stopAHU = std::make_unique<cStopAHU>(bacnetInterface, "101");

    // Invoke start, then stop via the invoker
    auto operator1 = std::make_unique<cOperator>(std::move(startAHU));
    operator1->invoke();
    operator1 = std::make_unique<cOperator>(std::move(stopAHU));
    operator1->invoke();

    return 0;
}