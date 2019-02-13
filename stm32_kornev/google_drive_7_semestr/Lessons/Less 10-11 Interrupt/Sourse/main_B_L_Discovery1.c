//підключаємо необхідні бібліотеки
//#include "stm32f4xx.h"
#include "inc_func.h"
#include "inc_interrupt.h"

/*******************************************************************
*  static value (global)
*******************************************************************/
// uint32_t i;
uint8_t led_n;
uint8_t _led_n;
//main function
int main ()
{

	init_gpiod();
	init_gpioa();
	irq0_enable();
	led_n = 0;
	_led_n = 0;
	//infinite loop
	while(1) {
		
		//while(!(GPIOA->IDR & GPIO_IDR_ID0)){} // чекаємо натискання кнопки
		//while((GPIOA->IDR & GPIO_IDR_ID0)){}  // чекаємо відпускання кнопки	
		// led_n змінюється обробником переривань
		disable_EXTI0;
		//if (led_n !=_led_n){
					switch (led_n){
			case 1 : toogle_pin_PD12; break;  // GPIOD->ODR ^= GPIO_ODR_OD12
			case 2 : {toogle_pin_PD13;   // GPIOD->ODR ^= GPIO_ODR_OD13
					   toogle_pin_PD12;}break;
				case 3 : toogle_pin_PD14; 
					   toogle_pin_PD13; 
					   ;break;  // GPIOD->ODR ^= GPIO_ODR_OD14
			case 4 : toogle_pin_PD15;
					   toogle_pin_PD14; break;  // GPIOD->ODR ^= GPIO_ODR_OD15
			default : {led_n = 0;_led_n=0;}
		}
	    enable_EXTI0;
		delay(500000);
		
	//}
}
}



/*******************************************************************/
