//
// file : consumer.c
// author: Yug Patel
// last modified: 3 November 2023
//

#include "common.h"

// Producer and Consumer talk to each other 
int main(){
    //create new thread
    //thread opens shared memory
    //loop{
    //  thread writes to table array in memory
    //  use semaphore to signal writing done
    //}

    struct sharedMemoryObj* producerObj;
    int retValue = shm_open("sharedMemoryObj",O_RDWR,0777);
    if(retValue == -1){ printf("%s Error in shm_open return value");}

    sem_init(&(producerObj->semNumEmptySlots), 1, 10); 
    sem_init(&(producerObj->semNumReadSlots), 1 , 0);
    // argument list, address to semaphore, 1 means semaphore is shared between 
    // producer and consumer and 0 is the initial value

    
    for(int i=0; i< 10; ++i){
        //Wait for consumer semaphore, intially value would be 0
        sem_wait(&producerObj->semNumEmptySlots);
            int item = rand() % 10 +1;
            producerObj->bufferArray[i] = item;
            printf("%s producer produced item %i", item);
        
        sem_post(&producerObj->semNumReadSlots);
    }

    shm_unlink("sharedMemoryObj");
}