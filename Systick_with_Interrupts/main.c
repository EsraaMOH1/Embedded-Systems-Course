#include <stdint.h>
#include <stddef.h>

#include "tm4c123gh6pm_registers.h"
#include "common_macros.h"
#define Enable_Exceptions()  __asm(" CPSIE I")
#define Disable_Exceptions()  __asm(" CPSID I")
#define Enable_Faults()  __asm(" CPSIE F")
#define Disable_Faults()  __asm(" CPSID F")


void SYSTICK_Init(void){
    SYSTICK_CTRL_REG =0;
    SYSTICK_RELOAD_REG=16000000-1;
    SYSTICK_CURRENT_REG=0;
    SYSTICK_CTRL_REG=0x007;
    NVIC_SYSTEM_PRI3_REG &=~(1<<31) &~(1<<30) &~(1<<29);
}

void Systick_handler(void){
    GPIO_PORTF_DATA_REG &= ~(1<<1) &~(1<<2) &~(1<<3);
    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
    GPIO_PORTF_DATA_REG |= (1<<1);
    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
    GPIO_PORTF_DATA_REG &= ~(1<<1) &~(1<<2) &~(1<<3);
    GPIO_PORTF_DATA_REG |= (1<<2);
    while(GET_BIT(SYSTICK_CTRL_REG,16)==0);
    GPIO_PORTF_DATA_REG &= ~(1<<1) &~(1<<2) &~(1<<3);
    GPIO_PORTF_DATA_REG |= (1<<2);

}

void SW1_Init(void)
{
    GPIO_PORTF_AMSEL_REG &= ~(1<<0);      /* Disable Analog on PF0 */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFFFF0;   /* Clear PMCx bits for PF0 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   &= ~(1<<0);      /* Configure PF0 as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<0);      /* Disable alternative function on PF0 */
    GPIO_PORTF_PUR_REG   |= (1<<0);       /* Enable pull-up on PF0 */
    GPIO_PORTF_DEN_REG   |= (1<<0);       /* Enable Digital I/O on PF0 */

    GPIO_PORTF_IS_REG &= ~(1<<0);
    GPIO_PORTF_IBE_REG &= ~(1<<0);
    GPIO_PORTF_IEV_REG |=(1<<0);
    GPIO_PORTF_IM_REG |=(1<<0);
    GPIO_PORTF_ICR_REG |=(1<<0);

    NVIC_PRI17_REG &=~(1<<21) &~(1<<22) &~(1<<23);
    NVIC_EN0_REG |=(1<<30);
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

void Led_Green_Init(void){
    GPIO_PORTF_AMSEL_REG &= ~(1<<3);      /* Disable Analog on PF3  */
    GPIO_PORTF_PCTL_REG  &= 0xFFFFF0FFF;   /* Clear PMCx bits for PF3 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<3);       /* Configure PF3 as output pin as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<3);      /* Disable alternative function on PF3  */
    GPIO_PORTF_DEN_REG   |= (1<<3);       /* Enable Digital I/O on PF3 */
    GPIO_PORTF_DATA_REG  &= ~(1<<3);      /* Clear bit 3 in Data register to turn off the led */

}


int main(void)
{

    SYSCTL_RCGCGPIO_REG |=(1<<5);
    while(GET_BIT(SYSCTL_PRGPIO_REG,5) == 0);


    SYSTICK_Init();
    Led_Red_Init();
    Led_Blue_Init();
    Led_Green_Init();
    Enable_Exceptions();
    Enable_Faults();


    while(1){


    }
    return 0;
}
