//
// multithread example
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

#include "producer.c"
#include "consumer.c"

#define THREAD_NUM 2
// #define PROCESS_NUM 2       

// sem_t  semEmpty;
// sem_t semFull;
//We use mutex to ensure data consistency
// pthread_mutex_t mutexBuffer;


int buffer[10];
int count =0;

int main(int argc, char* argv[]){
    srand(time(NULL));
    pthread_t th[THREAD_NUM];
    pthread_mutex_init(&mutexBuffer, NULL);

    sem_init(&semEmpty, 0, 10);// 10 becaise 10 empty slots in the beginning
    sem_init(&semFull,0 , 0); // 0 because we have 0 full slots in the beginning

    int i;
    for(i = 0; i<THREAD_NUM; i++){
        if(i%2 == 0){
            if(pthread_create(&th[i], NULL, &producer, NULL) != 0){
                perror("Failed to create thread");
            }
        }else{
            if(pthread_create(&th[i], NULL, &consumer, NULL) != 0){
                perror("Failed to create thread");
            }
        }
    }
    sem_destroy(&semEmpty);
    sem_destroy(&semFull);
    pthread_mutex_destroy(&mutexBuffer);
    return 0;
}

//Shared memory pointer
//