/*
 ============================================================================
 Name        : Lab2_EX2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//find max number in an array
#include <stdio.h>
#include <stdlib.h>

#define arr_size 5

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int arr[arr_size], max_num=0;

	printf("Enter 5 numbers:");

	for (int i=0; i<arr_size; i++){

		scanf("%d",&arr[i]);
	}
	for(int j=0;j<arr_size; j++){
		if(arr[j]>max_num){
			max_num=arr[j];
		}
	}
	printf("max number is: %d",max_num);


	return 0;
}
