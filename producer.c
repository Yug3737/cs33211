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
    shm_unlink("/ghkkljghkl");
    int retValue = shm_open("yugpatel3737", O_EXCL | O_RDWR | O_CREAT, 0666);// | tells it to do 2 things
    if(retValue == -1){ printf("Error in producer shm_open return value\n"); return -1;}

    //shm_open is creating a file
    
    if (ftruncate(retValue, sizeof(struct sharedMemoryObj)) == -1){
        printf("ftruncate failed :(\n");
        return -1;
    }
    
    producerObj = mmap(NULL, sizeof(*producerObj), PROT_READ | PROT_WRITE,
                           MAP_SHARED, retValue, 0);


    printf("\nretValue = %i\n", retValue);
    printf("\nerrno = %i\n", errno);


    sem_init(&producerObj->semNumEmptySlots, 1, 10); 
    sem_init(&producerObj->semNumReadSlots, 1 , 0);
    // argument list, address to semaphore, 1 means semaphore is shared between 
    // producer and consumer and 0 is the initial value

    
    for(int i=0; i< 10; ++i){
        // printf("Inside For loop producer\n");
        //Wait for consumer semaphore, intially value would be 0
        //Producer waits for numEmpty semaphore and increments numRead semaphore
        sem_wait(&producerObj->semNumEmptySlots);
        int item = rand() % 10 +1;
        producerObj->bufferArray[i] = item;
        printf("producer produced item %i \n", item);
        
        sem_post(&producerObj->semNumReadSlots);
    }

    // shm_unlink("yugpatel3737");
}