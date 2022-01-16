#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>

using namespace std;

volatile int counter = 0;
pthread_mutex_t myMutex;
void *worker_thread(void *param)
{
    for (int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&myMutex);
        counter++;
        cout << "thread: " << *((int *)param) << "            incremements counter: " << counter << "\n";
        pthread_mutex_unlock(&myMutex);
    }
    return 0;
}

int main()
{
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2, id3 = 3;
    pthread_mutex_init(&myMutex, 0);
    pthread_create(&thread1, NULL, &worker_thread, &id1);
    pthread_create(&thread2, NULL, &worker_thread, &id2);
    pthread_create(&thread3, NULL, &worker_thread, &id3);

    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_join(thread3, 0);

    pthread_mutex_destroy(&myMutex);
    return 0;
}