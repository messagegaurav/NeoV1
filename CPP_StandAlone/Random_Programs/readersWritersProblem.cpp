/* Created By:
 * @Author: gauravawasthi@outlook.com
 * @Date: 2022-01-26 23:19:20
 * @Last Modified by: gaurav
 * @Last Modified time: 2022-01-27 00:47:25
 */

#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;

int readersCount = 0;
int value = 0;
pthread_mutex_t mutex;
sem_t mySem;

void *writersJob(void *threadId)
{
    sem_wait(&mySem);
    cout << "\n update value: " << value << " by writer: " << *((int *)threadId);
    value = ++value;
    sem_post(&mySem);
    cout << "\n writer: " << *(int *)threadId << " released !!";
    pthread_exit((NULL));
}

void *readersJob(void *threadId)
{
    pthread_mutex_lock(&mutex);
    readersCount++;
    cout << "\n reader: " << *(int *)threadId << " taken mutex lock, readers count: " << readersCount;
    if (readersCount == 1)
    {
        sem_wait(&mySem);
        cout << "\n reader: " << *(int *)threadId << " taken lock on value";
    }
    pthread_mutex_unlock(&mutex);

    cout << "\n reader: " << *(int *)threadId << " read value: " << value;
    sleep(5);

    pthread_mutex_lock(&mutex);
    readersCount--;
    if (readersCount == 0)
    {
        sem_post(&mySem);
    }
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main()
{
    pthread_t reader[10], writer[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&mySem, 0, 1);

    int ret = 0;

    for (int i = 0; i < 2; i++)
    {
        if (ret = pthread_create(&writer[i], NULL, &writersJob, &i))
        {
            cout << "\n Failure creating thread: " << i;
            exit(1);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        if (ret = pthread_create(&reader[i], NULL, &readersJob, &i))
        {
            cout << "\n Failure creating thread: " << i;
            exit(1);
        }
    }

    sleep(3);

    for (int i = 0; i < 5; i++)
    {
        pthread_join(reader[i], NULL);
    }

    for (int i = 0; i < 2; i++)
    {
        pthread_join(writer[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&mySem);

    return 0;
}