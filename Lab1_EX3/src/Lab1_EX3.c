/*
 ============================================================================
 Name        : Lab1_EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*A simple Code to demonstrate the capability of the Compiler Optimization with
Logical operators.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

		int num;

		printf("Enter a num:");
		scanf("%d\n",&num);

		if((num%2) ==0)
			printf("Num %d is even\n",num);
		
		else
			printf("Num %d is odd\n",num);
		

		  return(0);
}
