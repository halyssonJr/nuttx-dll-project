#include <nuttx/config.h>
#include <stdio.h>

#include <sys/types.h>
#include <stdarg.h>
#include <syslog.h>

visibility_default int shrlib_sum(void)
{
	int a = 2, b = 10;
	return (a+b);
}

visibility_default int shrlib_mult(void)
{
	int a = 2, b = 10;
	return (a *b);
}