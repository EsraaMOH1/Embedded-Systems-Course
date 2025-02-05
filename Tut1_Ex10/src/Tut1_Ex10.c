/*
 ============================================================================
 Name        : Tut1_Ex10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Develop a Program that Continuously prompt the user for a calculation until they
choose to exit (Hint: Use the Do-While Loop)
Example:
Enter an operator (+, -, *, /):
Enter two operands: num1 and num2
Do you want to perform another calculation? (y/n):
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	char answer,operator;
	int num1,num2;

	do{
		printf("Enter an operator (+, -, *, /):\n");
		scanf(" %c",&operator);

		printf("Enter two operands: num1 and num2\n");
		scanf("%d  %d",&num1,&num2);


		switch(operator){
		case '+':
			printf("%d + %d =%d\n",num1,num2,num1+num2);
			break;
		case '*':
			printf("%d * %d =%d\n",num1,num2,num1*num2);
			break;
		case '-':
			printf("%d - %d =%d\n",num1,num2,num1-num2);
			break;
		case '/':
			printf("%d / %d =%d\n",num1,num2,num1/num2);
			break;
		}

		printf("Do you want to perform another calculation? (y/n):");
		scanf(" %c",&answer);

	}while(answer!='n');

		printf("Exit program!!");
}
