//
// file : consumer.c
// author: Yug Patel
// last modified: 3 November 2023
//

#include "common.h"

pthread_mutex_t mutexBuffer;


void* producer(void* args){
    while(1){
        //Produce
        int x = rand() % 10;
        // sleep(1);

        // Add to the buffer
        sem_wait(&semEmpty);


        buffer[count] = x;
        count++;


        sem_post(&semFull);
    }
}

// Producer and Consumer talk to each other 
int main(){
    //create new thread
    //thread opens shared memory
    //loop{
    //  thread writes to table array in memory
    //  use semaphore to signal writing done
    //}

    sharedMemoryObj proderObj;
    int retValue = shm_open("sharedMemoryObj",O_RDWR,0777);
    if(retValue == -1){ printf("%s Error in shm_open return value");}

    //
    sem_init(semEmpty, semFull);


}