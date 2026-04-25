/**
 * Main source of the firmware.
 */

#include "main.h"

static int32_t i = 0;

int main(void)
{
	HAL_Init();
	
	configOscClk();
	configDebugPort();
	
	printLog("\nThe firmware is running...");
	printLog("System clock is set to %ld HZ.", SystemCoreClock);

	// __disable_irq();		/* disable the all interrupts */

	/* Make the fake interrupt */
	NVIC_EnableIRQ(SPI1_IRQn);
	NVIC_SetPriority(SPI1_IRQn, 3);
	NVIC_SetPendingIRQ(SPI1_IRQn);
	
	while (1)
	{
		printLog("Hello from STM32! (#%ld)", i++);
		HAL_Delay(2000);
	}
}

