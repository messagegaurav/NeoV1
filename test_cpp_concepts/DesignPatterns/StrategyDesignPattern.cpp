#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

class cProtocolInterface
{
public:
    virtual void sendMsg(const string &msg) = 0;
    virtual void receiveMsg() = 0;
    virtual ~cProtocolInterface()
    {
        cout << "\n base interface cProtocolInterface destroyed...!!!!\n\n";
    }
};

class cBacnetProtocol : public cProtocolInterface
{
public:
    void sendMsg(const string &msg) override
    {
        cout << "Bacnet Protocol sending message: " << msg << endl;
    }

    void receiveMsg() override
    {
        cout << "Bacnet Protocol receiving message" << endl;
    }
    virtual ~cBacnetProtocol()
    {
        cout << "cBacnetProtocol destroyed...!!!!\n\n";
    }
};

class cMstpProtocol : public cProtocolInterface
{
public:
    void sendMsg(const string &msg) override
    {
        cout << "MSTP Protocol sending message: " << msg << endl;
    }

    void receiveMsg() override
    {
        cout << "MSTP Protocol receiving message" << endl;
    }
    virtual ~cMstpProtocol()
    {
        cout << "cMstpProtocol destroyed...!!!!\n\n";
    }
};

class cMetasysController
{
private:
    unique_ptr<cProtocolInterface> mProtocol;

public:
    void setProtocol(unique_ptr<cProtocolInterface> protocol)
    {
        mProtocol = move(protocol);
    }
    void performComm(const string &msg)
    {
        mProtocol->sendMsg(msg);
        mProtocol->receiveMsg();
    }
    virtual ~cMetasysController()
    {
        cout << "cMetasysController destroyed...!!!!\n\n";
    }
};

int main()
{
    cMetasysController controller;
    controller.setProtocol(make_unique<cBacnetProtocol>());
    controller.performComm("Bacnet Message 101");

    controller.setProtocol(make_unique<cMstpProtocol>());
    controller.performComm("MSTP Message 202");

    return 0;
}