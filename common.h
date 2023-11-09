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
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <errno.h>


struct sharedMemoryObj {
    sem_t  semNumEmptySlots;
    sem_t  semNumReadSlots;
    int bufferArray[10];
};

