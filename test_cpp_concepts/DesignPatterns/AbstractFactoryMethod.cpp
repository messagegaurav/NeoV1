#include <iostream>

using namespace std;

// abstract product interfaces
class cDeviceComm
{
public:
    virtual void startComm() = 0;
    virtual ~cDeviceComm()
    {
        cout << "\n base interface cDeviceComm destroyed...!!!!\n\n";
    }
};

class cDevParser
{
public:
    virtual void startParsing() = 0;
    virtual ~cDevParser()
    {
        cout << "\n base interface cDevParser destroyed...!!!!\n\n";
    }
};

// concrete product implementations

class cBacnetDevComm : public cDeviceComm
{
public:
    void startComm() override
    {
        cout << "Bacnet Communication Started\n";
    }
    virtual ~cBacnetDevComm()
    {
        cout << "cBacnetDevComm destroyed...!!!!\n\n";
    }
};

class cBacnetDevParser : public cDevParser
{
public:
    void startParsing() override
    {
        cout << "Bacnet Parsing Started\n";
    }
    virtual ~cBacnetDevParser()
    {
        cout << "cBacnetDevParser destroyed...!!!!\n\n";
    }
};

class cMstpDevComm : public cDeviceComm
{
public:
    void startComm() override
    {
        cout << "MSTP Communication Started\n";
    }
    virtual ~cMstpDevComm()
    {
        cout << "cMstpDevComm destroyed...!!!!\n\n";
    }
};

class cMstpDevParser : public cDevParser
{
public:
    void startParsing() override
    {
        cout << "cMstpDevParser Parsing Started\n";
    }
    virtual ~cMstpDevParser()
    {
        cout << "cMstpDevParser destroyed...!!!!\n\n";
    }
};

// Abstract Factory interface

class cProtocolFactory
{
public:
    virtual cDeviceComm *createDeviceComm() = 0;
    virtual cDevParser *createDevParser() = 0;
    virtual ~cProtocolFactory()
    {
        cout << "\n base interface cProtocolFactory destroyed...!!!!\n\n";
    }
};

// Concrete Factories implementation

class cBacnetProtocolFactory : public cProtocolFactory
{
public:
    cDeviceComm *createDeviceComm() override
    {
        return new cBacnetDevComm();
    }
    cDevParser *createDevParser() override
    {
        return new cBacnetDevParser();
    }
    virtual ~cBacnetProtocolFactory()
    {
        cout << "cBacnetProtocolFactory destroyed...!!!!\n\n";
    }
};
class cMstpProtocolFactory : public cProtocolFactory
{
public:
    cDeviceComm *createDeviceComm() override
    {
        return new cMstpDevComm();
    }
    cDevParser *createDevParser() override
    {
        return new cMstpDevParser();
    }
    virtual ~cMstpProtocolFactory()
    {
        cout << "cMstpProtocolFactory destroyed...!!!!\n\n";
    }
};

// Client code
void ProtocolImpl(cProtocolFactory &factory)
{
    cDeviceComm *deviceComm = factory.createDeviceComm();
    deviceComm->startComm();
    delete deviceComm;

    cDevParser *devParser = factory.createDevParser();
    devParser->startParsing();
    delete devParser;
}

int main()
{
    cBacnetProtocolFactory *bacnetFactory = new cBacnetProtocolFactory();
    ProtocolImpl(*bacnetFactory);
    delete bacnetFactory;

    cMstpProtocolFactory *mstpFactory = new cMstpProtocolFactory();
    ProtocolImpl(*mstpFactory);
    delete mstpFactory;
    return 0;
}