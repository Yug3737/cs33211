//
//Basic syntax for C language

//C does not have bool type
// Convention: 0 is false , non-0 is true
int isTall = 1;
isTall = 0;

#include <stdio.h>
#include <stdlib.h>

char testGrade = 'F';
char name[] = "Mike"; //array of characters
float gpa = 4.0;
int main(){
printf("%s, your grade is %c \n", name , testGrade);

//POINTERS      
int num = 10;
int* pNum = &num; // p in pNum is a naming convention

}

