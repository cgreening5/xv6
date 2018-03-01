/*
COMP4430 - Operating Systems 2
Dr. Rasit Eskicioglu
Assignment 2 - test program
	- This program tests malloc in allocating multiple pages-worth of memory.
	- The program achieves this by allocating 8192 single-byte wide chars with malloc and 8192 4-byte wide integers for a total of 40960 bytes, or 4 pages.
David Newson, Chris Greening
6847224, 6833899
*/

#include "types.h"
#include "stat.h"
#include "user.h"

//extern

void testMalloc()
{
        printf(1,"\n\n>  This program declares an int-pointer and allocates 8192 int-wide (4 byte) pieces of memory.\n>  Right after it declares a char-pointer and allocates 8192 char-wide (1 byte) pieces of memory.\n>  This program should therefore require 40960 bytes (or 4 pages) to be lazily allocated within it's process\n\n");
	
	int *testint = malloc(8192*sizeof(int));
	char *string = malloc(8192*sizeof(char));
	
	int *intptr = testint;
	char *strptr = string;
	int *intptr2 = &testint[8191];
	char *strptr2 = &string[8191];
	printf(1,"This prints out the addresses of the last allocated element for 'string' and 'testint'\n>  String[8191] address:%x    testint[8191] address:%x\n\n",strptr2,intptr2);
	printf(1,"This prints out the first and second element-addresses of 'string' and 'testint'\n>  String[0] and String[1] addresses:%x %x ||  testint[0] and [1] Addresses:%x %x\n\n",strptr,strptr+1,intptr,intptr+1);
	printf(1,"The differences between the last element and the first element of each array equates to 8192 elements, and for testint, the values are 4 bytes wide, and the string values are 1 byte wide.  All values are displayed in base-16\n");
	 
	
}

int main(void)
{
        testMalloc();
        exit();
}
