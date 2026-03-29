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
	
	while (1)
	{
		printLog("Hello from STM32! (#%ld)", i++);
		HAL_Delay(1000);
	}
}
 