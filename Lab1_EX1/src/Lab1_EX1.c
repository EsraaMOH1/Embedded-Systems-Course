/*
 ============================================================================
 Name        : Lab1_EX1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*A simple code to demonstrate the capability of the Bitwise operators on two
hexadecimal numbers.*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

		setvbuf(stdout,NULL,_IONBF,0);
		setvbuf(stderr,NULL,_IONBF,0);
		unsigned int x=0x05, y=0x0B;
		printf("%d\n",x&y); //anding
		printf("%d\n",x|y); //Orring
		printf("%d\n",x^y); //xoring
		printf("%d , %d",~x,~y); //one's complement



	return 0;
}
