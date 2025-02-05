/*
 ============================================================================
 Name        : Ass3_Ex6.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Develop a C Program to find a certain number in an array using linear search
algorithm.
Implement a Linear Search Function to search for the element in the required
array and return the index of its first occurrence.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int arr[5];
	int num,index;

	printf("Enter You array:");
	for(int i=0;i<5;i++){
		scanf(" %d",&arr[i]);
	}

	printf("Enter the number you want to search for:");
	scanf(" %d",&num);

	for(int i=0;i<5;i++)
	{
		if(arr[i]==num){
			printf("%d is found at index %d",num,i+1);
		}
	}

	return 0;
}
