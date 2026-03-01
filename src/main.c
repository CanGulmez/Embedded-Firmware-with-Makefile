/**
 ******************************************************************************
 * @file 	main.c
 * @author 	Ahmet Can GULMEZ
 * @brief 	Main source file.
 * 
 ******************************************************************************
 * @attention
 * 
 * Copyright (c) 2025 Ahmet Can GULMEZ.
 * All rights reserved.
 * 
 * This software is licensed under the MIT License.
 * 
 *****************************************************************************
 */

#include "main.h"

int main(void)
{
	HAL_Init();

	configOscClk();
	configDebugPort();

	printLog("The firmware is running...");

	while (1)
	{
		printLog("Hello from STM32!");
		HAL_Delay(1000);
	}
}
 
 
