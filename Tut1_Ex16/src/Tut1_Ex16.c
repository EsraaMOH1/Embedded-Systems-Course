/*
 ============================================================================
 Name        : Tut1_Ex15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C function that calculates the required heater activation time according to
the input temperature of water.
 - if input temperature is from 0 to 30, then required heating time = 7 mins.
 - if input temperature is from 30 to 60, then required heating time = 5 mins.
 - if input temperature is from 60 to 90, then required heating time = 3 mins.
 - if input temperature is more than 90, then required heating time = 1 mins.
 - if temperature is invalid (more than 100), return 0
Example: Input = 10 --> output = 7, Input = 35 --> output = 5
 */

#include <stdio.h>
#include <stdlib.h>

int temperature(int x){
	int time=0;

	if((x>=0)&& (x<=30)){
		time=7;
	}
	else if((x>=30)&& (x<=60)){
		time=5;
	}
	else if((x>=60)&& (x<=90)){
		time=3;
	}
	else if(x>=90){
		time=1;
	}
	else{
		time=0;
	}
	return time;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int temp;
	printf("Enter a temperature:");
	scanf("%d",&temp);

	int result=temperature(temp);

	printf("The heating time required is %d mins",result);

	return 0;
}
