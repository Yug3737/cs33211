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


