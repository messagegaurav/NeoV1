/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-31 10:08:48
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-31 12:05:21
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

    msgQId = msgget(keyId, IPC_CREAT | 0666);
    if (msgQId < 0)
    {
        cout << "\n failed with msgget()...exiting";
        exit(1);
    }

    mqData.mqStatus = MQType::TYPEA;
    strncpy(mqData.data, "Hey I am residing in MQ now...", sizeof(mqData.data));

    if (msgsnd(msgQId, &mqData, sizeof(mqData), 0) < 0)
    {
        cout << "\n failed in sending ...msgsend()";
        exit(1);
    }

    cout << "\n data has been sent to message Q now...";

    cout << "\n\n";
    return 0;
}
