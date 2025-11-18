#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Subsystem: BACnet protocol communication
class cBacnetProtocol
{
public:
    // Read a property from a device (mocked)
    string readData(int devId, string property)
    {
        return "Data from device " + to_string(devId) + " property " + property;
    }

    // Write a property to a device (mocked)
    void write(int devId, string property, string value)
    {
        cout << "Writing to device " << devId << " property " << property << " value " << value << endl;
    }

    ~cBacnetProtocol()
    {
        cout << "cBacnetProtocol Destructor Called" << endl;
    }
};

// Subsystem: Network Automation Engine (NAE)
class cNAEController
{
public:
    void startNAE() { cout << "NAE Controller Started" << endl; }
    void stopNAE() { cout << "NAE Controller Stopped" << endl; }
    ~cNAEController()
    {
        cout << "cNAEController Destructor Called" << endl;
    }
};

// Subsystem: Field Equipment Controller (FEC)
class cFECController
{
public:
    void startAHU() { cout << "FEC AHU Controller Started" << endl; }
    void stopAHU() { cout << "FEC AHU Controller Stopped" << endl; }
    ~cFECController()
    {
        cout << "cFECController Destructor Called" << endl;
    }
};

// Facade: simplifies interaction with multiple subsystems
class cFacadeInterface
{
private:
    unique_ptr<cBacnetProtocol> mBacnet; // BACnet comms
    unique_ptr<cNAEController> mNAE;     // NAE controller
    unique_ptr<cFECController> mFEC;     // FEC controller
    bool mInitialized = false;           // init state flag

public:
    // Bring all subsystems up (idempotent)
    void initializeSystems()
    {
        if (mInitialized)
        {
            cout << "Systems already initialized." << endl;
            return;
        }
        mBacnet = make_unique<cBacnetProtocol>();
        mNAE = make_unique<cNAEController>();
        mFEC = make_unique<cFECController>();

        mNAE->startNAE();
        mFEC->startAHU();
        mInitialized = true; // mark initialized
    }

    // Gracefully stop and release subsystems
    void shutdownSystems()
    {
        if (!mInitialized)
        {
            cout << "Systems not initialized." << endl;
            return;
        }
        mFEC->stopAHU();
        mNAE->stopNAE();

        mFEC.reset();
        mNAE.reset();
        mBacnet.reset();
        mInitialized = false; // mark uninitialized
    }

    // Query system status via BACnet
    void getSystemStatus()
    {
        if (!mInitialized)
        {
            cout << "Systems not initialized." << endl;
            return;
        }
        cout << "System Status: " << mBacnet->readData(101, "status") << '\n';
    }

    // Set a device parameter via BACnet
    void setSystemParameter(int devId, string parameter, string value)
    {
        if (!mInitialized)
        {
            cout << "Systems not initialized." << endl;
            return;
        }
        mBacnet->write(devId, parameter, value);
    }

    ~cFacadeInterface()
    {
        cout << "cFacadeInterface Destructor Called" << endl;
    }
};

int main()
{
    // Client uses only the Facade; internals remain hidden
    unique_ptr<cFacadeInterface> facade = make_unique<cFacadeInterface>();

    facade->initializeSystems();
    facade->setSystemParameter(101, "temperature", "22C");
    facade->getSystemStatus();
    facade->shutdownSystems();

    return 0;
}