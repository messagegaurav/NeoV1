/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-31 10:08:48
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-31 12:06:21
 */

#include "MessageQueue.h"
#include <sys/msg.h>
#include <sys/types.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex>
#include <string.h>

using namespace std;

int main()
{
    key_t keyId;
    int msgQId;

    MQData_t mqData;

    memset(&mqData, 0, sizeof(mqData));

    keyId = ftok("//home//gauravislucky//repos//NeoV1//msgQfile", 'x');
    if (keyId < 0)
    {
        cout << "\n failed to create key...exiting";
        exit(1);
    }

    msgQId = msgget(keyId, 0666);
    if (msgQId < 0)
    {
        cout << "\n failed with msgget()...exiting";
        exit(1);
    }

    if (msgrcv(msgQId, &mqData, sizeof(mqData), (long)MQType::TYPEA, 0) < 0)
    {
        cout << "\n failed in sending ...msgsend()";
        exit(1);
    }

    if (mqData.mqStatus == MQType::TYPEA)
    {
        cout << "\n msgrcv() read data: " << mqData.data;
    }

    cout << "\n data has been received from message Q, destroying it now...";
    if (msgctl(msgQId, IPC_RMID, 0))
    {
        cout << "\n msgctl() not successfull...";
        exit(1);
    }
    return 0;
}
