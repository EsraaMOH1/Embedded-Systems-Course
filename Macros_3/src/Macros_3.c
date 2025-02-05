/*
 ============================================================================
 Name        : Macros_3.c
 Author      : esraa
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "common_macros.h"

int main(void) {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

	unsigned char var=0;
		SET_BIT(var,0); //set bit number 0
		SET_BIT(var,1); //set bit number 1
		SET_BIT(var,2); //set bit number 2

		printf("var=0x%x\n",var);

		CLEAR_BIT(var,2); //clear bit number 2
		printf("var=0x%x\n",var);

		TOGGLE_BIT(var,2); //toggle bit number 2
		printf("var=0x%x\n",var);

		if(GET_BIT(var,2) == 1) //check if bit number 2 is set
		{
			CLEAR_BIT(var,2);
			printf("var=0x%x\n",var);
		}

		if(GET_BIT(var,2) == 0) //check if bit number 2 is cleared
		{
			SET_BIT(var,2);
			printf("var=0x%x\n",var);
		}

		return 0;

}
