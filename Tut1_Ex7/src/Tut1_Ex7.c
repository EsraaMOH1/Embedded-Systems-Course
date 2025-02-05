/*
 ============================================================================
 Name        : Tut1_Ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Code to calculate and print the factorial of any input number using
loops
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num=0;
	long long result=1;

	printf("Enter a number:\n");
	scanf("%d",&num);

	for(int i=0;num>=i;i++){
		result=result*num;
		num--;

	}
	printf("The result: %d\n",result);

	return 0;


}
