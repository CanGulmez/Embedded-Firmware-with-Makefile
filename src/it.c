/**
 * Interrupt Service Routines (ISRs) of the firmware.
 */

#include "main.h"

void SysTick_Handler(void) 
{
   HAL_IncTick();
}

void SPI1_IRQHandler(void)
{
	uint32_t priority;

	priority = NVIC_GetPriority(SPI1_IRQn);
	printLog("SPI1 data reading completed (priority: %ld).", priority);
}
