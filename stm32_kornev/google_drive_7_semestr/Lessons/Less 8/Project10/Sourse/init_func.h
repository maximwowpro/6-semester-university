/* якщо прототипи функцій ніде не визначені,
 * то визначити їх тут  */
 #ifndef __init_func_h
#define __init_func_h



// додамо бібліотеки 
#include "stm32f4xx.h"
//#include <stdint.h>

// визначимо макроси переключення кнокок
#define toogle_pin_PD12 GPIOD->ODR ^= GPIO_ODR_OD12  // "Виключне АБО"
#define toogle_pin_PD13 GPIOD->ODR ^= GPIO_ODR_OD13  // "Виключне АБО"
#define toogle_pin_PD14 GPIOD->ODR ^= GPIO_ODR_OD14  // "Виключне АБО"
#define toogle_pin_PD15 GPIOD->ODR ^= GPIO_ODR_OD15  // "Виключне АБО"

// функції ініціалізації GPIO
void init_gpiod(void);
void init_gpioa(void);


typedef unsigned long      uint32;
// функція програмної затримки
void delay(volatile uint32);

 
#endif

