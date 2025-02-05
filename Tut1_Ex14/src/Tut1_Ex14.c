/*
 ============================================================================
 Name        : Tut1_Ex14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Function that calculate the Fibonacci series using recursive method.
The Fibonacci Series: 0,1,1,2,3,5,8,13, 21..
 */

#include <stdio.h>
#include <stdlib.h>

long fibonacci( long n )
{
	if ( n == 0 || n == 1 ) //stopping condition
	{

		return n;
	}
	else
	{
		return fibonacci( n - 1 ) + fibonacci( n - 2 ); // recursion step
	}
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);


	long num;
	printf("Enter a number:");
	scanf("%d",&num);

	long result=fibonacci(num);

	printf("The result of fibonacci is %d",result);

	return 0;
}
