/*
 ============================================================================
 Name        : Ass2_Ex4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a Program to display number of “*” according to the value in each array
element.
 Ex: {3,11,5} -> 3 ***
 11 ***********
 5 *****
 */

#include <stdio.h>
#include <stdlib.h>

#define arr_size 3

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int arr[arr_size]={3,11,5};

	for(int i=0;i<arr_size;i++){
		for(int j=0;j<arr[i];j++){
			printf("*");
		}
		printf("\n");
	}


	return 0;
}
