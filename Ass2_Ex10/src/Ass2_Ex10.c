/*
 ============================================================================
 Name        : Ass2_Ex10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Develop a Program that converts all lower-case letters in a string to upper-case.
(Hint: Check the values of characters in the ASCII Table.)
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char arr[5];

	printf("Enter your array of letters:");

	for(int i=0;i<5;i++){
		scanf(" %c",&arr[i]);
	}
	for(int i=0;i<5;i++){
		if(arr[i]>='a'&& arr[i]<'z'){
			arr[i]-=32;
		}
	}
	printf("Your new array of letters:\n");

	for(int i=0;i<5;i++){
		printf(" %c",arr[i]);
	}

	return 0;
}
