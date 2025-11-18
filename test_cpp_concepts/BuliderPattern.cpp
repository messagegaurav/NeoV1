#include <iostream>
#include <string>
#include <memory>

using namespace std;

// Product: built by builders
class cController
{
public:
    string alarms, trend, schedule, network;

    // Display built parts (consider: make const)
    void show()
    {
        cout << "Alarms: " << alarms << endl;
        cout << "Trend: " << trend << endl;
        cout << "Schedule: " << schedule << endl;
        cout << "Network: " << network << endl;
    }

    virtual ~cController()
    {
        cout << "cController Destructor Called" << endl;
    }
};

// Builder interface: steps to build a controller
class cControllerInterface
{
public:
    virtual void buildAlarms() = 0;
    virtual void buildTrend() = 0;
    virtual void buildSchedule() = 0;
    virtual void buildNetwork() = 0;
    // Transfer product ownership to caller
    virtual unique_ptr<cController> getResult() = 0;
    virtual ~cControllerInterface() = default;
};

// Concrete builder: HVAC controller
class cHVACController : public cControllerInterface
{
private:
    // Owns product under construction
    unique_ptr<cController> mController = make_unique<cController>();

public:
    void buildAlarms() override { mController->alarms = "HVAC Alarms Configured"; }
    void buildTrend() override { mController->trend = "HVAC Trend Configured"; }
    void buildSchedule() override { mController->schedule = "HVAC schedule configured"; }
    void buildNetwork() override { mController->network = "HVAC network Configured"; }

    unique_ptr<cController> getResult() override
    {
        return move(mController); // one-shot: leaves builder empty
    }

    virtual ~cHVACController()
    {
        cout << "cHVACController Destructor Called" << endl;
    }
};

// Concrete builder: AHU controller
class cAHUController : public cControllerInterface
{
private:
    unique_ptr<cController> mController = make_unique<cController>();

public:
    void buildAlarms() override { mController->alarms = "AHU Alarms Configured"; }
    void buildTrend() override { mController->trend = "AHU Trend Configured"; }
    void buildSchedule() override { mController->schedule = "AHU schedule configured"; }
    void buildNetwork() override { mController->network = "AHU network Configured"; }

    unique_ptr<cController> getResult() override
    {
        return move(mController);
    }

    virtual ~cAHUController()
    {
        cout << "cAHUController Destructor Called" << endl;
    }
};

// Director: orchestrates build steps
class cControllerDirector
{
public:
    // Consumes builder (unique_ptr): builder not reusable after call
    unique_ptr<cController> constructController(unique_ptr<cControllerInterface> mDirector)
    {
        mDirector->buildAlarms();
        mDirector->buildTrend();
        mDirector->buildSchedule();
        mDirector->buildNetwork();
        return mDirector->getResult();
    }

    ~cControllerDirector()
    {
        cout << "cControllerDirector Destructor Called" << endl;
    }
};

int main()
{
    // Build HVAC
    unique_ptr<cControllerDirector> mDirector = make_unique<cControllerDirector>();
    auto controller = mDirector->constructController(make_unique<cHVACController>());
    controller->show();

    // Build AHU
    controller = mDirector->constructController(make_unique<cAHUController>());
    controller->show();

    return 0;
}