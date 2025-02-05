/*
 ============================================================================
 Name        : Lab1_Ex2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a C program to determine if a student is eligible to participate in an exam
based on the following criteria:
 - The student must be in either grade 10 or grade 12.
 - The student's age must be between 15 and 18 years (inclusive).
 - Additionally, the student must not have previously failed the exam.

 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	int grade=0;
	int age=0;
	int failed=0;

	printf("Enter grade:\n");
	scanf("%d",&grade);
	printf("Enter age:\n");
	scanf("%d",&age);
	printf("Enter num of failed exams: \n");
	scanf("%d",&failed);

	if((grade==10||grade==12) &&(15<=age && age<=18)&& (!failed)){

		printf("Student is eligible to take the exam");
	}
	else{
		printf("Student is not eligible to take the exam");
	}
	return 0;

}
