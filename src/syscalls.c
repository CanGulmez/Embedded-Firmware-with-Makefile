/**
 * Dummy syscall implementations of the firmware.
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
