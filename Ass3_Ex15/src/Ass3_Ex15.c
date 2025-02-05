/*
 ============================================================================
 Name        : Ass3_Ex15.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a program that uses nested structures to organize student details, including
name, age, and address.
It defines two structures: Address (containing street, city, state, and zipCode) and
Student (containing name, age, and a nested Address structure).
In the main function, a Student variable is declared. The program prompts the
user to enter the student's name, age, and address details. It uses gets to read
string inputs and scanf for numeric inputs. Finally, the program prints the
student’s details, including the nested address information.
 */

#include <stdio.h>
#include <stdlib.h>

struct address{
	char street[100];
	char city[100];
	char state[100];
	int zipcode;
};

struct student{
	char name[100];
	int age;
	struct address student_address;

};

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	struct student std1;

	printf("Enter student name:");
	gets(std1.name);

	printf("Enter student age:");
	scanf("%d",&std1.age);
	getchar();

	printf("Enter address details:\n");
	printf("Enter street name:");
	gets(std1.student_address.street);

	printf("Enter city name:");
	gets(std1.student_address.city);

	printf("Enter state name:");
	gets(std1.student_address.state);

	printf("Enter zip_code:");
	scanf(" %d",&std1.student_address.zipcode);


	printf("Student details:\n");
	printf("Student name:");
	puts(std1.name);
	printf("Student age: %d\n",std1.age);
	printf("Student address:\n");
	printf("street:");
	puts(std1.student_address.street);
	printf("city:");
	puts(std1.student_address.city);
	printf("state:");
	puts(std1.student_address.state);
	printf("zip_code: %d",std1.student_address.zipcode);


	return 0;
}
