
#include "init_func.h"

/* ініціализація GPIOD pins 12, 13, 14, 15 *****/
void init_gpiod(void)
 {
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

/*  ініціализація GPIOA pin 0  ***********************/	
	void init_gpioa(void)
 {	
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;		    // enable GPIOA
	GPIOA->MODER &= ~GPIO_MODER_MODE0_0;	// GPIOA to INPUT
	GPIOA->MODER &= ~GPIO_MODER_MODE0_1;	// 
 }
/*  функція програмної затримки на i тактів ***********/ 
	void delay(volatile uint32 i)
{
	while (i--);
}
