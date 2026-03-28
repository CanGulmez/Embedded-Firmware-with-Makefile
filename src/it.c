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

