//
// Producer & Consumer Problem 
// Operating System Lab 1
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


void* consumer(void* args){
    while(1){
        //Remove from the buffer
        sem_wait(&semFull);
        pthread_mutex_lock(&mutexBuffer);
        int y = buffer[count-1];
        count--;
        pthread_mutex_lock(&mutexBuffer);
        sem_post(&semEmpty);

        //Consume
        printf("Got %d\n", y);
        sleep(1);
    }
}
