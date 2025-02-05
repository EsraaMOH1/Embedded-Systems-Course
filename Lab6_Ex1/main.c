
#include "tm4c123gh6pm_registers.h"
#include "common_macros.h"

#define NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND 364

////to toggle only once when switch is pressed

void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (NUMBER_OF_ITERATIONS_PER_ONE_MILI_SECOND * n) );
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
    GPIO_PORTF_PCTL_REG  &= 0xFFF0F0FF;   /* Clear PMCx bits for PF2 to use it as GPIO pin */
    GPIO_PORTF_DIR_REG   |= (1<<2);       /* Configure PF2 as output pin as input pin */
    GPIO_PORTF_AFSEL_REG &= ~(1<<2);      /* Disable alternative function on PF2  */
    GPIO_PORTF_DEN_REG   |= (1<<2);       /* Enable Digital I/O on PF2 */
    GPIO_PORTF_DATA_REG  &= ~(1<<2);      /* Clear bit 2 in Data register to turn off the led */
}


int main(void)
{
    SYSCTL_RCGCGPIO_REG |=(1<<5);
    while(GET_BIT(SYSCTL_PRGPIO_REG,5) == 0);

    SW2_Init();
    Led_Red_Init();
    int var=0;

    while(1){
        if(GET_BIT(GPIO_PORTF_DATA_REG,4) == 0)
                {
            Delay_MS(30);
            if(GET_BIT(GPIO_PORTF_DATA_REG,4) == 0)
                    GPIO_PORTF_DATA_REG |= (1<<2);  /* Blue LED ON */
                    Delay_MS(500);
                   if(var==0)
                    GPIO_PORTF_DATA_REG &= ~(1<<2); /* Blue LED OFF */
                    Delay_MS(500);
                    var=1;
                }
                else
                {

                    GPIO_PORTF_DATA_REG &= ~(1<<2); /* Blue LED OFF */
                    var=0;
                }
    }
	return 0;
}
