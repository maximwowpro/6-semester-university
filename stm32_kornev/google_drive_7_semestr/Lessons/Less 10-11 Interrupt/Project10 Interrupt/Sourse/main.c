//підключаємо необхідні бібліотеки
//#include "stm32f4xx.h"
#include "inc_func.h"
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
		//user code should be here!!!
		switch ( ++ led_n){
			case 1 : GPIOD->ODR ^= GPIO_ODR_OD12; break; // toggle pin PD12
			case 2 : GPIOD->ODR ^= GPIO_ODR_OD13; break; // toggle pin PD13
			case 3 : GPIOD->ODR ^= GPIO_ODR_OD14; break; // toggle pin PD14
			case 4 : GPIOD->ODR ^= GPIO_ODR_OD15; break; // toggle pin PD15
			default : led_n = 0;
		}
	delay(500000);
	}
}

/*******************************************************************/
