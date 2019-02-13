#include "main.h"
#include "init.h"
//#include <stdint.h>
//#include "stm32f4xx.h"


/* функція ініціализації GPIOD pins 12, 13, 14, 15 *Board STM32F4 DISCOVERY*/
void LEDs_ini(void) {
/* 	  enable GPIO_D clock */
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
	
/*   set output mode for PD15, PD14, PD13, PD12 */
	GPIOD->MODER |= GPIO_MODER_MODE12_0 | GPIO_MODER_MODE13_0 | 
					GPIO_MODER_MODE14_0 | GPIO_MODER_MODE15_0;
	GPIOD->MODER &= ~ (GPIO_MODER_MODE15_1 | GPIO_MODER_MODE14_1 | 
					  GPIO_MODER_MODE13_1 | GPIO_MODER_MODE12_1); 
/* set push-pull output type for pins 12,13,14,15 of GPIOD  */
	GPIOD->OTYPER &= ~(GPIO_OTYPER_OT_12 | GPIO_OTYPER_OT_13 |
					   GPIO_OTYPER_OT_14 | GPIO_OTYPER_OT_15);
// set low speed for GPIOD
	GPIOD->OSPEEDR = 0;
// pull-up and pull-down resistors disabled
	GPIOD->PUPDR = 0;

// set low level for pins 12,13,14,55 of GPIOD
	GPIOD->ODR &= ~(GPIO_ODR_ODR_12 | GPIO_ODR_ODR_13 |
					GPIO_ODR_ODR_14 | GPIO_ODR_ODR_15);	
 }


// обробник переривання SysTick
volatile uint16_t delay_count=0;
uint32_t PWM_Counter=0;
uint16_t PWM_B=50;	//period
uint16_t PWM_A=5;		//duty cycle = (PWM_A/PWM_B+1) 
void SysTick_Handler(void)
{	
//	if (delay_count> 0)
//	{
//	delay_count--;
//	}
//void SysTick_PWM();
//}
 // функція PWM
//void SysTick_PWM(void){
	if (PWM_Counter >= PWM_B)
	{
		PWM_Counter = 0;
		RED_ON();
	} else if (PWM_Counter == PWM_A){
		PWM_Counter++;
		RED_OFF();
		} else {
		PWM_Counter++;
		}
	}

void delay_ms(uint16_t delay_temp){
    delay_count = delay_temp;
    while(delay_count){}
}
