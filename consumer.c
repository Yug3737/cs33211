//
// Producer & Consumer Problem 
// Operating System Lab 1
// file : consumer.c
// author: Yug Patel
// last modified: 3 November 2023
//
#include "common.h"

pthread_mutex_t mutexBuffer;


void* consumer(void* args){
    // while(1){
    //     //Remove from the buffer
    //     sem_wait(&semFull);

    //     int y = buffer[count-1];
    //     count--;

    //     sem_post(&semEmpty);

    //     //Consume
    //     printf("Got %d\n", y);
    //     sleep(1);
    // }
}

int main(){
    //create new thread
    //open shared memory
    // loop{
    //  read from table
    //  print result
    //  use semaphore to signal reading done
    //}

 struct sharedMemoryObj* consumerObj;
    int retValue = shm_open("sharedMemoryObj",O_RDWR,0777);
    if(retValue == -1){ printf("%s Error in shm_open return value");}

    //
    // sem_init(&(consumerObj->semNumEmptySlots), 1, 10); // We need an & here because
    // sem_init(&(consumerObj->semNumReadSlots), 1 , 0);

    // The semaphore semFull
    //consumerObj->bufferArray[];
    
    for(int i=0; i< 10; ++i){
        //Wait for consumer semaphore, intially value would be 0
        sem_wait(&consumerObj->semNumReadSlots);
            int item = rand() % 10;
            consumerObj->bufferArray[i] = item;
            printf("%s consumer read item %i", item);
        sem_post(&consumerObj->semNumReadSlots);

    }

    shm_unlink("sharedMemoryObj");

}