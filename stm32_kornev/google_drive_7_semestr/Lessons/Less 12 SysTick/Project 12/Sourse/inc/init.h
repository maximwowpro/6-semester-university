#ifndef INIT_H
#define INIT_H
#include "main.h"
//#include "stm32f4xx.h"
#include <stdint.h>


/* макроси */
#define RED_ON()	GPIOD->ODR |= GPIO_ODR_OD13
#define RED_OFF()	GPIOD->ODR &= ~GPIO_ODR_OD13

// функція ініціалізації GPIO для керування світлодіодами
void LEDs_ini(void); 
	
// обробник переривання SysTick
void SysTick_Handler(void);
// затримка ms
void delay_ms(uint16_t);
// функція PWM
void SysTick_PWM(void);
#endif

