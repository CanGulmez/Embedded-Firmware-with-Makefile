/**
 *******************************************************************************
 * @file 	main.c
 * @author 	Can GULMEZ
 * @brief 	Main source file.
 * 
 *******************************************************************************
 */

#include "main.h"

int main(void)
{
	static int32_t i = 0;

	HAL_Init();
	
	configOscClk();
	configDebugPort();
	
	printLog("\nThe firmware is running...");

	// __disable_irq();		/* disable the all interrupts */

	/* Make the fake interrupt */
	NVIC_EnableIRQ(SPI1_IRQn);
	NVIC_SetPriority(SPI1_IRQn, 3);
	NVIC_SetPendingIRQ(SPI1_IRQn);
	
	while (1)
	{
		printLog("Hello from STM32! (#%ld)", i++);
		HAL_Delay(1000);
	}
}

