//
// Producer & Consumer Problem 
// Operating System Lab 1
// file : consumer.c
// author: Yug Patel
// last modified: 7 November 2023
//
#include "common.h"

int main(){
    // MAIN IDEA
    // create new thread
    // open shared memory
    // loop{
    //  read from table
    //  print result
    //  use semaphore to signal reading done
    // }

    sleep(1); // to ensure the producer has enough time to create 

    int retValue = shm_open("yugpatel3737",O_RDWR,0666);
    /*
    if (ftruncate(retValue, sizeof(struct sharedMemoryObj)) == -1)
        errExit("ftruncate");
    */
    struct sharedMemoryObj* shmp = mmap(NULL, sizeof(*shmp), PROT_READ | PROT_WRITE,
                           MAP_SHARED, retValue, 0);
    // mmap creates the shared memory buffer

    if(retValue == -1){ printf("Error in consumer shm_open return value\n");}
    printf("\nretValue = %i\n", retValue);
    printf("\nerrno = %i\n", errno);
    // errno stands for no such file or directory

    
    for(int i=0; i< 10; ++i){

        //Wait for consumer semaphore, intially value would be 0
        sem_wait(&shmp->semNumReadSlots);
            //int item = rand() % 10;
            int item = shmp->bufferArray[i]; //write random item
            printf("consumer read item %i\n", item); //%i is a placeholder
            // %s means looking for a string as a parameter
        sem_post(&shmp->semNumEmptySlots); //increases semaphore value for producer


    }

    shm_unlink("yugpatel3737");

}

//Consumer is unable to 