/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-30 23:53:47
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-31 00:02:12
 */

#include "SharedMemory.h"
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main()
{
    key_t keyId;
    int shmId;

    SMData_t *smData;

    keyId = ftok("//home//gauravislucky//repos//NeoV1//shmfile", 'x');
    shmId = shmget(keyId, sizeof(SMData_t), 0666);
    if (shmId < 0)
    {
        cout << " \n Reader: Failed to create shared memory...";
        exit(1);
    }

    smData = (SMData_t *)shmat(shmId, (void *)0, 0);
    if (smData < 0)
    {
        cout << "\n Reader: attaching the shared memory failed...";
        exit(1);
    }

    cout << "\n Reader: data has been written now..";

    smData->status = SharedMemStatus::TAKEN;
    cout << "\n Reader: data: " << smData->data;

    shmdt((void *)smData);
    cout << "\n destroying the shared memory now...";
    shmctl(shmId, IPC_RMID, NULL);
    return 0;
}