/*
 * Created on Mon Jan 17 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

using namespace std;
sem_t mySem;
void *semWait(void *param)
{

    cout << "thread: " << *((int *)param) << "       Into critical section and doin some work \n";
    sleep(4);
    sem_wait(&mySem);
    cout << "thread: " << *((int *)param) << " done with my work now exiting.. \n";

    return 0;
}

void *semPost(void *param)
{

    cout << "thread: " << *((int *)param) << "  let me release sem \n";

    sem_post(&mySem);

    cout << "thread: " << *((int *)param) << " sem is now released \n";

    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2, thread3;
    int id1 = 1, id2 = 2;
    sem_init(&mySem, 0, 1);
    pthread_create(&thread1, NULL, &semWait, &id1);
    sleep(2);
    pthread_create(&thread2, NULL, &semPost, &id2);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    sem_destroy(&mySem);
    return 0;
}
