/**
 ******************************************************************************
 * @file 	main.h
 * @author 	Can GULMEZ
 * @brief 	Main header file.
 * 
 ******************************************************************************
 */

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#include "stm32f4xx_hal.h"

/* Global and General Definitions */

#define BUFFER_SIZE				64
#define DATA_SIZE					512
#define SAMPLE_SIZE				(DATA_SIZE * 2)

#define FILE						__FILE__
#define LINE						__LINE__
#define PACKED						__attribute__((packed))
#define NORETURN					__attribute__((noreturn))
#define DEPRECATED				__attribute__((deprecated))
#define ALIGNED(n)				__attribute__((aligned(n)))
#define SECTION(s)				__attribute__((section(s)))

#define STATUS(status) 			((status == HAL_ERROR) 		? "ERROR" 	: 	\
									 	 (status == HAL_BUSY) 		? "BUSY"		:	\
										 (status == HAL_TIMEOUT)	? "TIMEOUT" :	\
										 "UNDEFINED")

/*****************************************************************************/
/*****************************************************************************/

/* Peripheral Handlers */

extern RCC_OscInitTypeDef iosc;
extern RCC_ClkInitTypeDef iclk;
extern GPIO_InitTypeDef igpio;
extern UART_HandleTypeDef huart4;

/*****************************************************************************/
/*****************************************************************************/

/**
 * Transmit the logs from MCU to PC over serial UART line.
 */
#define printLog(format, ...)																		\
{																											\
	char buffer[BUFFER_SIZE];																		\
																											\
	snprintf(buffer, BUFFER_SIZE, format "\r\n", ##__VA_ARGS__);						\
	HAL_UART_Transmit(&huart4, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);	\
}

/**
 * Transmit the HAL error from MCU to PC over serial UART line.
 */
#define printError(status, format, ...)														\
{																											\
	char buffer[BUFFER_SIZE];																		\
																											\
	snprintf(buffer, BUFFER_SIZE, "*** " format 	" (STATUS = %s) "						\
		"(%s::%d) ***\r\n", ##__VA_ARGS__, STATUS(status), FILE, LINE);				\
	HAL_UART_Transmit(&huart4, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);	\
}

/*****************************************************************************/
/*****************************************************************************/

/* Function Prototypes */

extern int _read(int, char *, int);
extern int _write(int, char *, int);
extern int _lseek(int, int, int);
extern int _close(int);

extern void configOscClk(void);
extern void configDebugPort(void);
extern void SysTick_Handler(void);
