/*
 ============================================================================
 Name        : Tut1_Ex8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a program to display a full pyramid using stars pattern taking the number of
rows from the user as input.
Ex if User Enters Number of Rows = 5:
*
***
*****
*******
*********
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int row,row_num;

	printf("Enter the number of rows:");
	scanf("%d",&row);

	for(row_num=0; row_num<row;row_num++){
		for(int j=0;j<row-row_num-1;j++){
			printf(" "); //blank spaces
		}
		for(int j=0;j<(2*row_num+1);j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
