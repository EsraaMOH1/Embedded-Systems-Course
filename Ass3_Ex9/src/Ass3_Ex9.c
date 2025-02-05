/*
 ============================================================================
 Name        : Ass3_Ex9.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a function which, given a string, return TRUE if all characters are distinct and
FALSE if any character is repeated
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int check_str (char *str){
	int result= TRUE;
	for (int i=0; str[i]!='\0';i++){
		for(int j=i+1;str[j]!='\0';j++){
			if(str[i]==str[j]){
				result= FALSE;
			}
		}
	}
	return result;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char str[100];
	printf("Enter a string:");
	gets(str);
	int result=check_str(str);

	if(result==TRUE){
		printf("all characters are distinct");
	}
	else{
		printf("A character is repeated");
	}
	return 0;
}
