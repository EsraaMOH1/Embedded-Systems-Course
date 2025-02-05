/*
 ============================================================================
 Name        : Ass3_Ex14.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Write a program that calculates the area of a rectangle using a pointer to a
Rectangle structure
It defines a Rectangle structure with length and width as its members. The
function calculateArea takes a pointer to a Rectangle and returns the area by
accessing length and width through the pointer.
In the main function, a Rectangle variable is declared and initialized, and a pointer
to this variable is assigned. The calculateArea function is then called using the
pointer, and the calculated area is printed
 */

#include <stdio.h>
#include <stdlib.h>

struct Rectangle{
	int length;
	int width;


};

int calculateArea(struct Rectangle *ptr){
	int area=(ptr->length)*(ptr->width);
	return area;

}
int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	struct Rectangle rect;
	struct Rectangle *ptr= &rect;

	printf("Enter length of rectangle:");
	scanf("%d",&rect.length);
	printf("Enter width of rectangle:");
	scanf("%d",&rect.width);

	int result=calculateArea(ptr);

	printf("Area of rectangle is %d",result);



	return 0;
}
