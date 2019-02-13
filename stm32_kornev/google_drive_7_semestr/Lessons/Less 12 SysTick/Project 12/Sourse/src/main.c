#include "main.h"
#include "init.h"
#include <stdint.h>

//main function
 int main(void){ 
	LEDs_ini();
	void SystemCoreClockUpdate(void);
	SysTick_Config(SystemCoreClock/1000);//1 ms
		 
	 while(1) 
	{
		//RED_ON();
		//delay_ms(5000); //"Trap"
		//RED_OFF();
		//delay_ms(1);
	}
	
} 

