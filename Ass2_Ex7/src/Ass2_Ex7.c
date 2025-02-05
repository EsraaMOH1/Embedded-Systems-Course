/*
 ============================================================================
 Name        : Ass2_Ex7.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C Code to take 2 multi-dimension arrays from the user then calculate the
sum of them and store it in a multi-dimension array and print it to the user
 */

#include <stdio.h>
#include <stdlib.h>

#define arr_rowsize 2
#define arr_colsize 3

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int arr1[arr_rowsize][arr_colsize];
	int arr2[arr_rowsize][arr_colsize];
	int result[arr_rowsize][arr_colsize];

	printf("Enter values for first array:");

	for(int i=0;i<arr_rowsize;i++){
		for(int j=0; j<arr_colsize;j++){
			printf("Enter value of arr1[%d][%d]",i,j);
			scanf("%d",&arr1[i][j]);
		}
		printf("2ndrow:\n");
		printf("\n");
	}

	printf("Enter values for second array:");

		for(int i=0;i<arr_rowsize;i++){
			for(int j=0; j<arr_colsize;j++){
				printf("Enter value of arr2[%d][%d]",i,j);
				scanf("%d",&arr2[i][j]);
			}
			printf("2ndrow:\n");
			printf("\n");
		}

		for(int i=0;i<arr_rowsize;i++){
					for(int j=0; j<arr_colsize;j++){

						result[i][j]=arr1[i][j]+arr2[i][j];
					}
					printf("\n");
		}
		for(int i=0;i<arr_rowsize;i++){
					for(int j=0; j<arr_colsize;j++){

						printf("%d\t",result[i][j]);
						if(j==arr_colsize-1){
							printf("\n");
						}
					}
					printf("\n");
		}

	return 0;
}
