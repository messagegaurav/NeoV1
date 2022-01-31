/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-30 23:43:08
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-31 00:07:39
 */

#include "SharedMemory.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    key_t keyId;
    int shmId;
    SMData_t *smData;

    keyId = ftok("//home//gauravislucky//repos//NeoV1//shmfile", 'x');
    shmId = shmget(keyId, sizeof(SMData_t), 0666 | IPC_CREAT);
    if (shmId < 0)
    {
        cout << "\n Shared memory creation failed...";
        exit(1);
    }
    cout << "\n Writer: shared memory created...";

    smData = (SMData_t *)shmat(shmId, (void *)0, 0);
    if (smData < 0)
    {
        cout << "\n Writer: error attaching shared memory..";
    }

    usleep(3);
    smData->status = SharedMemStatus::NOT_READY;
    strncpy(smData->data, "Hey I am residing in shared memory now", sizeof(smData->data));

    smData->status = SharedMemStatus::FILLED;

    cout << "\n start the client now...";

    cout << "\n Writer: data has been read by the client, going ahead and destroying the Shared memory now...";
    shmdt((void *)smData);

    cout << "\n Writer: removed shared memory now...";
    cout << "\n\n";
    return 0;
}