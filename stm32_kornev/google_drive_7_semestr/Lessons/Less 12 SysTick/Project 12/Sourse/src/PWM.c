#include "init.h"
#include "main.h"

uint8_t PWM_Counter=0;
uint8_t PWM_A=5; 
uint8_t	PWM_B=20;

void Systick_PWM(void)
{
	if (PWM_Counter >= PWM_B)
	{
		PWM_Counter = 0;
		RED_ON();
	} else if (PWM_Counter == PWM_A){
		PWM_Counter++;
		RED_OFF();
		} else {
		PWM_Counter++;
		}
		
}
	
	