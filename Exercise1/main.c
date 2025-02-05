/*
 * Copyright (c) 2017-2019, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,

 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 *  ======== main.c ========
 */
#include <stdint.h>
#include <stddef.h>

#include "tm4c123gh6pm_registers.h"
#include "common_macros.h"

void SYSTICK_Init(void){
    SYSTICK_CTRL_REG =0;
    SYSTICK_RELOAD_REG=8000000-1;
    SYSTICK_CURRENT_REG=0;
}

void SW2_Init(void)
{
    GPIO_PORTF_AMSEL_REG &= ~(1<<4);      /* Disable Analog on PF4 */
    GPIO_PORTF_PCTL_REG  &= 0xFFF0FFFF;   /* Clear PMCx bits for PF4 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   &= ~(1<<4);      /* Configure PF4 as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<4);      /* Disable alternative function on PF4 */
    GPIO_PORTF_PUR_REG   |= (1<<4);       /* Enable pull-up on PF4 */
    GPIO_PORTF_DEN_REG   |= (1<<4);       /* Enable Digital I/O on PF4 */
}

void Led_Red_Init(void)
{
    GPIO_PORTF_AMSEL_REG &= ~(1<<2);      /* Disable Analog on PF2  */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFF0FF;   /* Clear PMCx bits for PF2 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<2);       /* Configure PF2 as output pin as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<2);      /* Disable alternative function on PF2  */
    GPIO_PORTF_DEN_REG   |= (1<<2);       /* Enable Digital I/O on PF2 */
    GPIO_PORTF_DATA_REG  &= ~(1<<2);      /* Clear bit 2 in Data register to turn off the led */
}

void Led_Blue_Init(void){
    GPIO_PORTF_AMSEL_REG &= ~(1<<1);      /* Disable Analog on PF1  */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFF0F;   /* Clear PMCx bits for PF1 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<1);       /* Configure PF1 as output pin as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<1);      /* Disable alternative function on PF1  */
    GPIO_PORTF_DEN_REG   |= (1<<1);       /* Enable Digital I/O on PF1 */
    GPIO_PORTF_DATA_REG  &= ~(1<<1);      /* Clear bit 1 in Data register to turn off the led */

}

void Led_Yellow_Init(void){
    GPIO_PORTF_AMSEL_REG &= ~(1<<3);      /* Disable Analog on PF3  */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFF0FFF;   /* Clear PMCx bits for PF3 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<3);       /* Configure PF3 as output pin as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<3);      /* Disable alternative function on PF3  */
    GPIO_PORTF_DEN_REG   |= (1<<3);       /* Enable Digital I/O on PF3 */
    GPIO_PORTF_DATA_REG  &= ~(1<<3);      /* Clear bit 3 in Data register to turn off the led */

}


int main(void)
{
    SYSTICK_Init();
    SYSCTL_RCGCGPIO_REG |=(1<<5);
    while(GET_BIT(SYSCTL_PRGPIO_REG,5) == 0);

    SW2_Init();
    Led_Red_Init();
    Led_Blue_Init();
    Led_Yellow_Init();

    int var=0;

    while(1){
        if(GET_BIT(GPIO_PORTF_DATA_REG,4) == 0){
                while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
            if(GET_BIT(GPIO_PORTF_DATA_REG,4) == 0){
                    GPIO_PORTF_DATA_REG |= (1<<1); /* Red LED ON */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
                    GPIO_PORTF_DATA_REG |= (1<<2);  /* Blue LED ON */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
                    GPIO_PORTF_DATA_REG |= (1<<3);  /* Yellow LED ON */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
            }
                   if(var==0){
                    GPIO_PORTF_DATA_REG &= ~(1<<1); /* Red LED OFF */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
                    GPIO_PORTF_DATA_REG &= ~(1<<2); /* Blue LED OFF */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
                    GPIO_PORTF_DATA_REG &= ~(1<<3); /* Yellow LED OFF */
                    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
                    var=1;
                   }
                }
                else
                {
                    GPIO_PORTF_DATA_REG &= ~(1<<1); /* Red LED OFF */
                    GPIO_PORTF_DATA_REG &= ~(1<<2); /* Blue LED OFF */
                    GPIO_PORTF_DATA_REG &= ~(1<<3); /* Yellow LED OFF */
                    var=0;
                }
    }
    return 0;
}

