#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

// Target Interface
class cBacnetComm
{
public:
    virtual void readProp(const string &str) = 0;
    virtual void writeProp(const string &msg, const string &reg) = 0;
    virtual ~cBacnetComm()
    {
        cout << "\n base interface cBacnetComm destroyed...!!!!\n\n";
    }
};

// Adaptee Class
class cModbus
{
public:
    void readReg(int reg)
    {
        cout << "Modbus reading register: " << reg << endl;
    }

    void writeReg(int reg, const string &val)
    {
        cout << "Modbus writing value: " << val << " to register: " << reg << endl;
    }

    ~cModbus()
    {
        cout << "cModbus destroyed...!!!!\n\n";
    }
};

// Adapter Class
class cModBusToBacnet : public cBacnetComm
{
private:
    unique_ptr<cModbus> mModbusPtr;

public:
    cModBusToBacnet(unique_ptr<cModbus> modbus)
    {
        mModbusPtr = move(modbus);
    }

    void readProp(const string &Bacnetreg) override
    {
        int reg = mapBacnetToModReg(Bacnetreg);
        mModbusPtr->readReg(reg);
    }

    void writeProp(const string &msg, const string &reg) override
    {
        int modReg = mapBacnetToModReg(reg);
        mModbusPtr->writeReg(modReg, msg);
    }

    int mapBacnetToModReg(const string &reg)
    {
        // Simple mapping logic for demonstration
        if (reg == "AnalogPoint")
            return 1001;
        else if (reg == "DigitalPoint")
            return 2001;
        return 0; // Default or error case
    }

    virtual ~cModBusToBacnet()
    {
        cout << "cModBusToBacnet destroyed...!!!!\n\n";
    }
};

int main()
{
    cModBusToBacnet adapter(make_unique<cModbus>());

    cBacnetComm *bacnetComm = &adapter;
    bacnetComm->readProp("AnalogPoint");
    bacnetComm->writeProp("75.5", "AnalogPoint");

    return 0;
}