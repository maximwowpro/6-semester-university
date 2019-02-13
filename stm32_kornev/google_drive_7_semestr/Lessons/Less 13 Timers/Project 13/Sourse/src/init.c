#include "main.h"
#include "init.h"
//#include <stdint.h>
//#include "stm32f4xx.h"

//***********************************************************
//function ініціализації GPIOD pins 12, 13, 14, 15 *Board STM32F4 DISCOVERY
//***********************************************************
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
 
//********************************************************** 
//function  ініціалізація таймера TIM6 і переривань
//**********************************************************
  void Timers_ini(void) {
  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;    //подаем тактирование на TIM6
  TIM6->PSC	= 8000-1;                //настроить делитель для формирования миллисекунд
  TIM6->ARR     = 500-1;                   //2Hz - это 500 миллисекунд
  TIM6->DIER    = TIM_DIER_UIE;        	 //разрешить событие от таймера
  //разрешить перезагрузку и включить таймер
  TIM6->CR1     = TIM_CR1_CEN | TIM_CR1_ARPE;
  //разрешить прерывания от таймера              
  NVIC_EnableIRQ (TIM6_DAC_IRQn);	     
 
  __enable_irq();	                 //разрешить "глобальные" прерывания
  }
  
//***************************************************************************
//function обробник переривання від TIM6                                    //
//***************************************************************************
void TIM6_DAC_IRQHandler(void)
{ 
  if(TIM6->SR & TIM_SR_UIF)		//це переривання від TIM6 ?

  {
    TIM6->SR &= ~TIM_SR_UIF;	//сбросить флаг
    Toogle_RED();        		//инвертровати RED LED
  }  
}

