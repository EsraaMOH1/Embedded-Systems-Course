/*
 ============================================================================
 Name        : Lab2_Ex3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define row_num 2
#define col_num 5
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int arr[row_num][col_num], sum=0;

	printf("Enter numbers:");

	for (int i=0; i<row_num; i++){
		for(int j=0;j<col_num; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int j=0;j<row_num; j++){
		for (int i=0; i<col_num; i++){
			sum+=arr[j][i];
		}
	}
	printf("Sum is: %d",sum);
	return 0;
}
