/*
 * Created on Mon Jan 17 2022
 *
 * Copyright (c) 2022 Gaurav Awasthi
 * Understanding CPP Concepts
 */

#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;

static int counter = 0;
pthread_mutex_t myMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myCond = PTHREAD_COND_INITIALIZER;

void *producer(void *param)
{
    pthread_mutex_lock(&myMutex);
    cout << "thread: " << *((int *)param) << "            incremements counter: " << counter << "\n";
    counter++;
    if (counter == 1)
    {
        cout << "signalled \n";
        pthread_cond_signal(&myCond);
    }
    sleep(2);
    pthread_mutex_unlock(&myMutex);
    return 0;
}

void *consumer(void *param)
{
    int ret = 0;
    pthread_mutex_lock(&myMutex);
    cout << "thread: " << *((int *)param) << "            trying to read counter: " << counter << "\n";
    while (counter != 1)
    {
        cout << "waiting on condition \n";
        pthread_cond_wait(&myCond, &myMutex);
    }

    ret = counter;
    pthread_mutex_unlock(&myMutex);
    cout << " \n thread: " << *((int *)param) << " read counter value: " << counter;
    return &ret;
}

typedef struct base
{
    int i;
    int j;
    int result;
} base_t;

void *returnStruct(void *ptr)
{
    base_t *myBase = (base_t *)ptr;
    myBase->result = myBase->i + myBase->j;
    pthread_exit(myBase);
}

int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_cond_init(&myCond, 0);

    base_t myBase;
    myBase.i = 10;
    myBase.j = 20;
    int id1 = 1, id2 = 2;
    pthread_mutex_init(&myMutex, 0);
    pthread_create(&thread1, NULL, &producer, &id1);

    pthread_create(&thread2, NULL, &consumer, &id2);

    pthread_create(&thread3, 0, &returnStruct, &myBase);

    pthread_join(thread1, 0);

    pthread_join(thread2, 0);

    pthread_join(thread3, 0);

    cout << "\n struct values now: myBase.result: " << myBase.result;

    pthread_mutex_destroy(&myMutex);
    pthread_cond_destroy(&myCond);
    cout << "\n\n";
    return 0;
}