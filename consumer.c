//
// Producer & Consumer Problem 
// Operating System Lab 1
// file : consumer.c
// author: Yug Patel
// last modified: 3 November 2023
//
#include "common.h"

int main(){
    // MAIN IDEA
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

    // The semaphore semFull
    //consumerObj->bufferArray[];
    
    for(int i=0; i< 10; ++i){
        //Wait for consumer semaphore, intially value would be 0
        sem_wait(&consumerObj->semNumReadSlots);
            int item = rand() % 10;
            consumerObj->bufferArray[i] = item; //write random item
            printf("%s consumer read item %i", item);
        sem_post(&consumerObj->semNumEmptySlots); //increases semaphore value for producer

    }

    shm_unlink("sharedMemoryObj");

}