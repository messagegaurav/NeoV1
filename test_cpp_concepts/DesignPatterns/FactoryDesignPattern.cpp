#include <iostream>

using namespace std;

enum ProtocolType
{
    BACNET,
    MODBUS,
    AMEV
};

class ProtocolHandler
{
public:
    virtual void initialize() = 0;
    virtual void sendData(const string &data) = 0;
    virtual ~ProtocolHandler()
    {
        cout << "\n base interface ProtocolHandler destroyed...!!!!\n\n";
    }
};

class BacnetHandler : public ProtocolHandler
{
public:
    void initialize() override
    {
        cout << "Bacnet Protocol Initialized\n";
    }

    void sendData(const string &data) override
    {
        cout << "Sending data over Bacnet: " << data << "\n";
    }
    ~BacnetHandler() override
    {
        cout << "BacnetHandler destroyed...!!!!\n\n";
    }
};

class ModbusHandler : public ProtocolHandler
{
public:
    void initialize() override
    {
        cout << "Modbus Protocol Initialized\n";
    }

    void sendData(const string &data) override
    {
        cout << "Sending data over Modbus: " << data << "\n";
    }
    ~ModbusHandler() override
    {
        cout << "ModbusHandler destroyed...!!!!\n\n";
    }
};

class AmevHandler : public ProtocolHandler
{
public:
    void initialize() override
    {
        cout << "Amev Protocol Initialized\n";
    }

    void sendData(const string &data) override
    {
        cout << "Sending data over Amev: " << data << "\n";
    }
    ~AmevHandler() override
    {
        cout << "Amev destroyed...!!!!\n\n";
    }
};

class ProtocolFactory
{
public:
    static ProtocolHandler *createService(const ProtocolType &pPType)
    {
        switch (pPType)
        {
        case BACNET:
            return new BacnetHandler();

        case MODBUS:
            return new ModbusHandler();

        case AMEV:
            return new AmevHandler();

        default:
            return nullptr;
        }
    }
};

int main()
{
    ProtocolHandler *protocol = ProtocolFactory::createService(MODBUS);
    if (protocol != nullptr)
    {
        protocol->initialize();
        protocol->sendData("Temperature=25C");
        delete protocol;
    }
    else
    {
        cout << "Unsupported ProtocolHandler ..!!!\n\n";
    }
    return 0;
}