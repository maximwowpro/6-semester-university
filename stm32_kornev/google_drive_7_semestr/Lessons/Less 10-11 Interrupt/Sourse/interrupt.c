
#include "inc_func.h"
#include "inc_interrupt.h"

extern uint8_t led_n;

	
/*    Функція дозвілу переривання IRQ0 *****/
void irq0_enable(void){
 /* Керування EXTI (External interrupt controller0 *******/
 //   enable то SYSCFGREG clock 
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
//    обрати РА0 у якості джерела переривання IRQ0(підключити PA0 до EXTI0)
	SYSCFG->EXTICR[1] |= SYSCFG_EXTICR1_EXTI0_PA;
//    дозволяємо переривання (знімаємо маску IM0 з IRQ0) 
	EXTI->IMR |= EXTI_IMR_IM0;
//    реагувати на фронт (Rising trigger) 
	EXTI->RTSR |= EXTI_RTSR_TR0;	
//    реагувати на спад (Falling trigger) розкоментуйте рядок знизу, якщо треба */   
    //EXTI->RTSR |= EXTI_FTSR_TR0; 

/* Керування NVIC(Nested Vectired Interrupt Controller) */

    NVIC_SetPriority(EXTI0_IRQn,0);    //  встановити приоритет 0 для IRQ0
	NVIC_ClearPendingIRQ(EXTI0_IRQn);  //  скинути очикуючє переривання IRQ0
	NVIC_EnableIRQ(EXTI0_IRQn);        //  дозволіти переривання IRQ0
//    загальний дозвіл переривань (CMSIS-функція скидає біт PRIMASK) 
	__enable_irq();
}

 /* **************************************
 *       Обробник переривання IRQ0      *
 * *************************************/ 

void EXTI0_IRQHandler(void){
	//забороняємо переривання EXTI0
	EXTI->IMR&= ~EXTI_IMR_MR0;
	//робимо затримку в 20 мс для захисту від брязкоту контактів
	delay(20000);
	//якщо вивід встановився в одиницю
	if ((GPIOA->IDR & GPIO_IDR_ID0)) {
		// вставити відповідний код 
		//if (led_n < 5) 
			led_n++;      // додати кількість натисканькнопки
		//else (led_n=0);
		}
		// або, наприклад, інвертувати стан світлодіода (PD12)
		/* toogle_pin_PD12 ;  /GPIOD->ODR ^= GPIO_ODR_OD12 */
	
	//очищуємо прапор очікуючого переривання(Pending bit)
	EXTI->PR|= EXTI_PR_PR1;
	//дозволяємо переривання від EXTI0
	EXTI->IMR|=(EXTI_IMR_MR0);
  }
