#include <nuttx/config.h>
#include <stdio.h>

#include <sys/types.h>
#include <stdarg.h>
#include <dlfcn.h>
#include <syslog.h>

visibility_default void shrlib_sum(void)
{
	int a = 2, b = 10;
	printf("a+b = %d\n", a+b);
}

visibility_default void shrlib_mult(void)
{
	int a = 2, b = 10;
	printf("a*b = %d\n", a*b);
}