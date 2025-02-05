/*
 ============================================================================
 Name        : Tut1_Ex17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a program to print the square for numbers from 1 to 10
 */

#include <stdio.h>
#include <stdlib.h>

int square(int x){

}
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int num=0;

	for(int i=0;i<10;i++){
		num++;
		printf("%d",square(num));
	}
	return 0;
}
