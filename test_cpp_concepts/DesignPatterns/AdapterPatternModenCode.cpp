#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>
#include <stdexcept>

using namespace std;

// Target Interface with concepts-like design
class cBacnetComm
{
public:
    virtual void readProp(const string &str) = 0;
    virtual void writeProp(const string &msg, const string &reg) = 0;
    virtual ~cBacnetComm() = default;
};

// Adaptee Class with move semantics
class cModbus
{
private:
    int mDeviceId;

public:
    explicit cModbus(int deviceId = 1) : mDeviceId(deviceId) {}

    void readReg(int reg)
    {
        cout << "Device " << mDeviceId << " - Modbus reading register: " << reg << endl;
    }

    void writeReg(int reg, const string &val)
    {
        cout << "Device " << mDeviceId << " - Modbus writing value: " << val
             << " to register: " << reg << endl;
    }

    ~cModbus()
    {
        cout << "cModbus (Device " << mDeviceId << ") destroyed\n\n";
    }
};

// Advanced Adapter with registry pattern
class cModBusToBacnet : public cBacnetComm
{
private:
    unique_ptr<cModbus> mModbusPtr;
    unordered_map<string, int> mRegMapping;

    // Lambda-based mapping with default factory
    using MapperFunc = function<int(const string &)>;
    MapperFunc mCustomMapper;

public:
    explicit cModBusToBacnet(unique_ptr<cModbus> modbus,
                             MapperFunc customMapper = nullptr)
        : mModbusPtr(move(modbus)), mCustomMapper(customMapper)
    {
        initializeDefaultMapping();
    }

    void readProp(const string &Bacnetreg) override
    {
        try
        {
            int reg = mapBacnetToModReg(Bacnetreg);
            if (reg == 0)
            {
                throw runtime_error("Invalid register: " + Bacnetreg);
            }
            mModbusPtr->readReg(reg);
        }
        catch (const exception &e)
        {
            cerr << "Error in readProp: " << e.what() << endl;
        }
    }

    void writeProp(const string &msg, const string &reg) override
    {
        try
        {
            int modReg = mapBacnetToModReg(reg);
            if (modReg == 0)
            {
                throw runtime_error("Invalid register: " + reg);
            }
            mModbusPtr->writeReg(modReg, msg);
        }
        catch (const exception &e)
        {
            cerr << "Error in writeProp: " << e.what() << endl;
        }
    }

    // Add custom register mapping
    void addMapping(const string &bacnetReg, int modbusReg)
    {
        mRegMapping[bacnetReg] = modbusReg;
    }

    int mapBacnetToModReg(const string &reg)
    {
        // Use custom mapper if provided
        if (mCustomMapper)
        {
            return mCustomMapper(reg);
        }

        // Use registry if exists
        auto it = mRegMapping.find(reg);
        if (it != mRegMapping.end())
        {
            return it->second;
        }

        // Default mapping
        if (reg == "AnalogPoint")
            return 1001;
        else if (reg == "DigitalPoint")
            return 2001;
        else if (reg == "CounterPoint")
            return 3001;

        return 0;
    }

    virtual ~cModBusToBacnet()
    {
        cout << "cModBusToBacnet destroyed\n\n";
    }

private:
    void initializeDefaultMapping()
    {
        mRegMapping = {
            {"Temp", 5001},
            {"Humidity", 5002},
            {"Pressure", 5003}};
    }
};

// Factory pattern for creating adapters
class AdapterFactory
{
public:
    static unique_ptr<cBacnetComm> createAdapter(int deviceId)
    {
        return make_unique<cModBusToBacnet>(make_unique<cModbus>(deviceId));
    }

    static unique_ptr<cBacnetComm> createAdapterWithCustomMapper(
        int deviceId,
        function<int(const string &)> mapper)
    {
        return make_unique<cModBusToBacnet>(
            make_unique<cModbus>(deviceId),
            mapper);
    }
};

int main()
{
    // Traditional adapter
    cout << "=== Traditional Adapter ===\n";
    auto adapter1 = AdapterFactory::createAdapter(1);
    adapter1->readProp("AnalogPoint");
    adapter1->writeProp("75.5", "AnalogPoint");

    cout << "\n=== Adapter with Registry Mapping ===\n";
    auto adapter2 = AdapterFactory::createAdapter(2);
    if (auto *pAdapter = dynamic_cast<cModBusToBacnet *>(adapter2.get()))
    {
        pAdapter->addMapping("CustomReg", 9001);
        adapter2->readProp("CustomReg");
        adapter2->writeProp("100", "CustomReg");
    }

    cout << "\n=== Adapter with Lambda Mapper ===\n";
    auto customMapper = [](const string &reg) -> int
    {
        if (reg == "Speed")
            return 4001;
        if (reg == "Torque")
            return 4002;
        return 0;
    };
    auto adapter3 = AdapterFactory::createAdapterWithCustomMapper(3, customMapper);
    adapter3->readProp("Speed");
    adapter3->writeProp("3000", "Speed");

    cout << "\n=== Cleanup ===\n";
    return 0;
}