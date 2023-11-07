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
    while(1){
        //Remove from the buffer
        sem_wait(&semFull);

        int y = buffer[count-1];
        count--;

        sem_post(&semEmpty);

        //Consume
        printf("Got %d\n", y);
        sleep(1);
    }
}

int main(){
    //create new thread
    //open shared memory
    // loop{
    //  read from table
    //  print result
    //  use semaphore to signal reading done
    //}

    sharedMemoryObj consumerObj;
    shm_open();

}