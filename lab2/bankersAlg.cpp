//
// file: bankersAlg.cpp
// author: Yug Patel
// last modified: 29 November 2023
//
#include <iostream>
#include <fstream>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::ifstream; using std::string;

const int numProcesses = 5;
const int numResources = 3;

void calculateNeed(int need[numProcesses][numResources], int maxm[numProcesses][numResources],
                   int allot[numProcesses][numResources]){
    // Calculating Need of each Process
    for (int i = 0 ; i < numProcesses ; i++)
        for (int j = 0 ; j < numResources ; j++)
 
            // Needed instances = maximum instances - allocated instances
            need[i][j] = maxm[i][j] - allot[i][j];
}
 
// Function to find the system is in safe state or not
bool isSafe(int processes[], int avail[], int maxm[][numResources],
            int allot[][numResources]){

    int need[numProcesses][numResources];
 
    // Function to calculate instance need matrix
    calculateNeed(need, maxm, allot);
 
    // Mark all processes as unfinished
    bool finish[numProcesses] = {0};
 
    // To store safe sequence
    int safeSeq[numProcesses];
 
    // Make a copy of available resources
    int work[numResources];
    for (int i = 0; i < numResources ; i++)
        work[i] = avail[i];
 
    // While all processes are not finished
    // or system is not in safe state.
    int count = 0;
    while (count < numProcesses){
        // Find a process which is not finish and
        // whose needs can be satisfied with current
        // work[] resources.
        bool found = false;
        for (int p = 0; p < numProcesses; p++){
            // First check if a process is finished,
            // if no, go for next condition
            if (finish[p] == 0){
                // Check if for all resources of
                // current P need is less
                // than work
                int j;
                for (j = 0; j < numResources; j++)
                    if (need[p][j] > work[j])
                        break;
 
                // If all needs of p were satisfied.
                if (j == numResources){
                    // Add the allocated resources of
                    // current P to the available/work
                    // resources i.e.free the resources
                    for (int k = 0 ; k < numResources ; k++)
                        work[k] += allot[p][k];
 
                    // Add this process to safe sequence.
                    safeSeq[count++] = p;
 
                    // Mark this p as finished
                    finish[p] = 1;
                    found = true;
                }
            }
        }
 
        // If we could not find a next process in safe
        // sequence.
        if (found == false){
            cout << "System is not in safe state";
            return false;
        }
    }
 
    // If system is in safe state then print the safe sequence
    cout << "System is in safe state.\nSafe"
         " sequence is: ";
    for (int i = 0; i < numProcesses ; i++)
        cout << safeSeq[i] << " ";
 
    return true;
}
 
int main(){
    int processes[] = {0, 1, 2, 3, 4};
    int avail[3]; // Available instances of resources
    // {3, 3, 2};
    int maxm[][numResources];
    int avail[][numResources];
    
    ifstream fin("input.txt");
    while(!fin.eof()){
        string tempStr;
        std::getline(fin, tempStr,'\n');
        if(tempStr == "Allocation" && tempStr != "Maximum" ){
            std::getline(fin, tempStr, '\n');
            int i = 0;
            int j = 0;
            for(i = 0; i < 5 ; ++i){
                for(j = 0; j < 3; ++j){
                    avail[i][j] = tempStr[2j+1];
                }
                std::getline(fin,tempStr, '\n');
            }
        }
        if(tempStr == "Maximum" && tempStr != "Available"){
            std::getline(fin, tempStr, '\n');
            int i = 0;
            int j = 0;
            for(i = 0; i < 5 ; ++i){
                for(j = 0; j < 3; ++j){
                    maxm[i][j] = tempStr[2j+1];
                }
                std::getline(fin,tempStr, '\n');
            }
        }
        if(tempStr == "Available"){
            avail[0] = 3;
            avail[1] = 3;
            avail[2] = 2;
        }
    }


    // Maximum R that can be allocated to processes
    // int maxm[][numResources] ;
 
    // Resources allocated to processes
    // int allot[][numResources] ;
 
    // Check system is in safe state or not
    isSafe(processes, avail, maxm, allot);
 
    return 0;
}