This is the README.md file for Operating Systems Lab2 (CS33211).
This C++ lab was about simulating the Banker's Algorithm for Deadlock Avoidance.

The program consists of 2 files, bankersAlg.cpp and input.txt.
The input.txt file consists of the number of resource instances(A,B,C) that are currently allocated to each process(P0 through P4).
The cpp file reads the numbers from the txt file and determines if the current system is in safe state or not.
If it is, it prints out the correct order in which the resource instances should be allocated in order to avoid a deadlock and
cater to each of the process's demands.

**How to Run the Program?**
To run the program please use a terminal like Visual Studio Code.
Also make sure that both the files are in the same directory.
Use any C++ compiler and write the command: **g++ bankersAlg.cpp**.
Then to view the output run the default file a.out by: **./a.out**

**Output**
According to the resource instances given on Canvas assignment, the system is in safe state and the 
order of processes turns out to be P1,P3,P4,P0,P2.
