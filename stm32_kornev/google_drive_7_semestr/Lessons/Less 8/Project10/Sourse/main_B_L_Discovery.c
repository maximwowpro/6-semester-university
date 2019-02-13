//підключаємо необхідні бібліотеки
//#include "stm32f4xx.h"
#include "init_func.h"
/*******************************************************************
*  static value (global)
*******************************************************************/
uint32_t i;
uint8_t led_n;

//main function
int main ()
{

	init_gpiod();
	init_gpioa();
	led_n = 0;
	//infinite loop
	while(1) {
		
		while(!(GPIOA->IDR & GPIO_IDR_ID0)){} // чекаємо натискання кнопки
		while((GPIOA->IDR & GPIO_IDR_ID0)){}  // чекаємо відпускання кнопки	
		
		switch (++led_n){
			case 1 : toogle_pin_PD12; break;  // GPIOD->ODR ^= GPIO_ODR_OD12
			case 2 : toogle_pin_PD13; break;  // GPIOD->ODR ^= GPIO_ODR_OD13
			case 3 : toogle_pin_PD14; break;  // GPIOD->ODR ^= GPIO_ODR_OD14
			case 4 : toogle_pin_PD15; break;  // GPIOD->ODR ^= GPIO_ODR_OD15
			default : led_n = 0;
		}
	delay(500000);
	}
}

/*******************************************************************/
