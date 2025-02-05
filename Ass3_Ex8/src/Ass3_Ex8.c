/*
 ============================================================================
 Name        : Ass3_Ex8.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a program to count the number of occurrences of a specific character in a
string.
It defines a function Count_Character that returns an integer and takes a pointer
to a character (as string) and a character as parameters. The function iterates
through the string, counting how many times the specified character appears.
In the main function, the program reads a string and a character from the user,
calls the Count_Character function to count occurrences of the character in the
string, and then prints the result.

 */

#include <stdio.h>
#include <stdlib.h>

int Count_Character (char *arr, char letter ){

	int count_occurrencies=0;

	for(int i=0; arr[i]!='\0';i++){
		if(arr[i]== letter){
			count_occurrencies++;
		}
	}
	return count_occurrencies;
}

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char string[5];
	char letter;
	printf("Enter Your array of letters:\n");
	gets(string);

	printf("Enter the letter you want to search for:");
	scanf(" %c",&letter);


	int result= Count_Character (string, letter);

	printf("Searching for %c --> result = %d ",letter,result);

	return 0;
}
