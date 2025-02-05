/*
 ============================================================================
 Name        : Tut1_Ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Develop a program that takes a month number (1-12) as input and prints the
number of days in this month using switch statement
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num=0;
	int even=0;

	printf("Enter month number:\n");
	scanf("%d",&num);


	switch(num){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
		printf("Num of days is 31\n");
		break;
	case 2:
		printf("Num of days is 28\n");
		break;
	case 4:
	case 6:
	case 9:
	case 10:
	case 11:
	case 12:
		printf("Num of days is 30\n");
		break;
	}
	return 0;

}
