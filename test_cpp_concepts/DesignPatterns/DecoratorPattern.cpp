#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

// Component interface: defines sensor behavior
class cSensorInterface
{
public:
    virtual string readData() = 0; // get sensor reading
    virtual ~cSensorInterface() = default;
};

// Concrete component: actual temperature sensor
class cTemperatureSensor : public cSensorInterface
{
public:
    string readData() override
    {
        cout << "Reading temperature data from sensor." << endl;
        return "Temperature: 25C";
    }

    virtual ~cTemperatureSensor() = default;
};

// Decorator base: wraps another cSensorInterface instance
class cSensorDecorator : public cSensorInterface
{
protected:
    unique_ptr<cSensorInterface> mSensor; // owns wrapped component

public:
    // constructor takes ownership of component (move semantics)
    explicit cSensorDecorator(unique_ptr<cSensorInterface> sensor) : mSensor(move(sensor)) {}
    // readData() delegates to wrapped component
    string readData() override
    {
        return mSensor->readData();
    }

    virtual ~cSensorDecorator() = default;
};

// Logging decorator: adds logging behavior
class cLoggingInterface : public cSensorDecorator
{
public:
    // readData() logs then returns wrapped readData()
    explicit cLoggingInterface(unique_ptr<cSensorInterface> sensor) : cSensorDecorator(move(sensor)) {}

    string readData() override
    {
        string val = cSensorDecorator::readData();
        cout << "Logged Data: " << val << endl;
        return val;
    }

    virtual ~cLoggingInterface()
    {
        cout << "cLoggingInterface Destructor Called" << endl;
    }
};

// Alarming decorator: adds alarm check to reading
class cAlarmingInterface : public cSensorDecorator
{
public:
    // readData() checks threshold, triggers alarm if needed
    explicit cAlarmingInterface(unique_ptr<cSensorInterface> sensor) : cSensorDecorator(move(sensor)) {}

    string readData() override
    {
        string val = cSensorDecorator::readData();
        if (val.find("Temperature: 25C") != string::npos)
        {
            cout << "Alarm: Temperature threshold exceeded!" << endl;
        }
        cout << "Alarmed Data: " << val << endl;
        return val;
    }

    virtual ~cAlarmingInterface()
    {
        cout << "cAlarmingInterface Destructor Called" << endl;
    }
};

// Encryption decorator: modifies output for encryption
class cEncryptionInterface : public cSensorDecorator
{
public:
    // readData() returns encrypted wrapped readData()
    explicit cEncryptionInterface(unique_ptr<cSensorInterface> sensor) : cSensorDecorator(move(sensor)) {}

    string readData() override
    {
        return "Encrypted: " + cSensorDecorator::readData();
    }

    virtual ~cEncryptionInterface()
    {
        cout << "cEncryptionInterface Destructor Called" << endl;
    }
};

int main()
{
    // Build decorator chain: Encryption(Alarming(Logging(TemperatureSensor)))
    // Call readData() -> flows through decorators to base sensor
    // unique_ptr ensures proper cleanup in reverse order
    unique_ptr<cSensorInterface> sensor = make_unique<cTemperatureSensor>();

    auto sensorDecorator = move(make_unique<cEncryptionInterface>(
        make_unique<cAlarmingInterface>(
            make_unique<cLoggingInterface>(move(sensor)))));

    cout << sensorDecorator->readData() << endl;

    return 0;
}