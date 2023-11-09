# cs33211
Hello. 
This is Yug Patel and this is the readMe file for my Operating Systems Project.
The lab is on Producer and Consummer/ Shared Buffer Problem.

**What does the code contain?**
The project consists of 3 files in C language.
common.h has the shared struct that is used by both the producer and consumer processes.
producer.c and consumer.c include common.h and have their separate main() functions to use the shared memory buffer.

**How to run the program**
You can use any c language compiler.
There are 3 lines of command-line arguments.
1st: gcc producer.c -pthread -lrt -o producer 
2nd: gcc consumer.c -pthread -lrt -o consumer
3rd: ./producer & ./consumer & #producer and consumer are the names of our object files

**Problems faced**
1. Initially, my implementation used 3 arrays representing the shared buffer. But then I realized that I was not actually using the shared. So I created the shared buffer with shm_open() function giving it the appropriate arguments.
2. Another issue I faced, in the end, was that after the became compilable, it was not printing the printf statement in between the sem_wait() and sem_post() functions in both producer and consumer files. This issue was easily solved when I removed %s since I was not giving it any placeholder.
3. A bigger issue was in the end when the return Value for the shm_open function showed an error. The problem was that the producer was done producing the items and used to unlink the shared memory object before consumer even started consuming. Hence we realized that calling unlink in producer doesn't help and we just wrote unlink statement in consumer file.


