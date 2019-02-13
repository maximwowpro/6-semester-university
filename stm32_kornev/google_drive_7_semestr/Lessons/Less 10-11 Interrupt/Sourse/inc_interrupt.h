#ifndef INC_INTERRUPT_H
#define INC_INTERRUPT_H
/* якщо прототипи функцій ніде не визначені,
 * то визначити їх тут  */ 

 // додамо бібліотеки 
#include "stm32f4xx.h"
#include <stdint.h>
// визначимо макроси 
#define disable_EXTI0 EXTI->IMR&= ~EXTI_IMR_MR0
#define enable_EXTI0 EXTI->IMR|=(EXTI_IMR_MR0)
/* ****     прототипи функцій   ***********************/

// функція дозвілу переривання IRQ0
void irq0_enable(void);

// прототип обробника переривання Button 1 (PA0 -> EXTI0) 
void EXTI1_IRQHandler(void);

#endif /* if the functions are already defined */ 

