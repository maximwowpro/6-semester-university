#ifndef INC_FUNC_H
#define INC_FUNC_H
/* якщо прототипи функцій ніде не визначені,
 * то визначити їх тут  */ 

 // додамо бібліотеки 
#include "stm32f4xx.h"
#include <stdint.h>

// визначимо макроси переключення кнопок
#define toogle_pin_PD12 GPIOD->ODR ^= GPIO_ODR_OD12  // "Виключне АБО"
#define toogle_pin_PD13 GPIOD->ODR ^= GPIO_ODR_OD13  // "Виключне АБО"
#define toogle_pin_PD14 GPIOD->ODR ^= GPIO_ODR_OD14  // "Виключне АБО"
#define toogle_pin_PD15 GPIOD->ODR ^= GPIO_ODR_OD15  // "Виключне АБО"

// функції ініціалізації GPIO
void init_gpiod(void);
void init_gpioa(void);


// функція програмної затримки
void delay(volatile uint32_t);

 
#endif /* if the functions are already defined */ 

