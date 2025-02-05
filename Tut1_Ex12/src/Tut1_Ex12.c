/*
 ============================================================================
 Name        : Tut1_Ex12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Function that takes two numbers and checks for the minimum value of
them and return it
 */

#include <stdio.h>
#include <stdlib.h>

int min(int x, int y){
	int min=0;
	if(x>y){
		min=y;
	}
	else{
		min=x;
	}
	return min;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num1,num2;
	printf("Enter 2 numbers:");
	scanf("%d %d",&num1,&num2);

	int result=min(num1,num2);

	printf("The result is %d",result);

	return 0;
}
