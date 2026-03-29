/**
 ******************************************************************************
 * @file 	syscalls.c
 * @author 	Can GULMEZ
 * @brief 	Dummy syscall implementations.
 * 
 ******************************************************************************
 */

#include "main.h"

int _read(int fd, char *ptr, int len)
{
	return 0;
}

int _write(int fd, char *ptr, int len)
{
	return 0;
}

int _lseek(int fd, int ptr, int dir)
{
	return 0;
}

int _close(int fd)
{
	return 0;
}
