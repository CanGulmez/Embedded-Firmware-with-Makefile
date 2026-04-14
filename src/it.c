/**
 *******************************************************************************
 * @file 	it.c
 * @author 	Can GULMEZ
 * @brief 	Interrupt Service Routine (IRQ) handlers.
 * 
 *******************************************************************************
 */

#include "main.h"

void SysTick_Handler(void) 
{
   HAL_IncTick();
}

void SPI1_IRQHandler(void)
{
	uint32_t pri;

	pri = NVIC_GetPriority(SPI1_IRQn);
	printLog("SPI1 data reading completed (%ld).", pri);
}
