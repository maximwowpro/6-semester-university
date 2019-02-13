#ifndef INIT_H
#define INIT_H
#include "main.h"
//#include "stm32f4xx.h"
#include <stdint.h>


/* макрос переключення світлодіода*/
#define Toogle_RED()	GPIOD->ODR ^= GPIO_ODR_OD13

// функція ініціалізації GPIO для керування світлодіодами
void LEDs_ini(void); 
// функція ініціалізації TIM6	
void Timers_ini(void);
// обробник переривання TIM6
void TIM6_DAC_IRQHandler(void);


#endif

