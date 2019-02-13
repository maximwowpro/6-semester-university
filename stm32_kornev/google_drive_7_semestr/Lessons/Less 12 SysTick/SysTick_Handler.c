uint16_t delay_count=0; // global variable
 void SysTick_Handler (void)
{ 
/* Тут будем делать, что-нибудь полезное. 
	Например, уменьшать значение счетчика тиков на 1 		*/	
	if (dela_count>0) // If delay_count=10 after 10ms delay_count=0 
	{  
		delay_count--;  
	} 
} 	

