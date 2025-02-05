/*
 ============================================================================
 Name        : Ass3_Ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Develop a program to find the longest consecutive occurrence of a given number
in an array.
It defines The FindLongestConsecutive function, which returns an integer, takes
three parameters: the size of the Array_size, a pointer to the array, and the
Number to search for. The function iterates through the array, counting the
consecutive occurrences of the specified number. It tracks the longest sequence of
consecutive occurrences and returns this count.
Example: Array = {1,2,2,3,3,3,3,4,4,4,4,3,3,3} and searching for 3 --> result = 4
In the main function, an array is defined and initialized, and the
FindLongestConsecutive function is called to find the longest consecutive
occurrence of a certain number. The result is then printed.
 */

#include <stdio.h>
#include <stdlib.h>

int FindLongestConsecutive (int arr[],int size, int num ){
	int occurrencies=0;
	int max_occurrencies=0;
	for(int i=0; i<size;i++){
		if(arr[i]==num){
			occurrencies++;
			if(occurrencies>max_occurrencies){
				max_occurrencies=occurrencies;
			}
		}
		else{
			occurrencies=0; //to clear count
		}
	}
	return max_occurrencies;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int array_size= 14;
	int arr[array_size];
	int number=0;

	printf("Enter Your array of numbers:");
	for(int j=0; j<array_size;j++){
		scanf(" %d",&arr[j]);
	}

	printf("Enter the number you want to search for:");
	scanf(" %d",&number);


	int result= FindLongestConsecutive (arr,array_size, number);

	printf("Searching for %d --> result = %d ",number,result);

	return 0;
}
