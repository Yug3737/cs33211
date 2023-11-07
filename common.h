//
// Common file between producer and consumer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/mman.h>


struct sharedMemoryObj{
    sem_t  semEmpty;
    sem_t semFull;
    int bufferArray[10];
};

