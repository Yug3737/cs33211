//
// file : consumer.c
// author: Yug Patel
// last modified: 3 November 2023
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

int buffer[10];
int count =0;
sem_t  semEmpty;
sem_t semFull;

pthread_mutex_t mutexBuffer;


void* producer(void* args){
    while(1){
        //Produce
        int x = rand() % 10;
        // sleep(1);

        // Add to the buffer
        sem_wait(&semEmpty);
        pthread_mutex_lock(&mutexBuffer);

        buffer[count] = x;
        count++;

        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFull);

    }
}