
#ifndef __moec_util_h
#define __moe_util_h

#include <stdarg.h>

/**
 * retrurn true if char* arg1 is equal 
 * to any other n given char*  va_args
 */
bool strcmp_m(char *s1, int n, ...) {
	va_list va;
	int i;
	char *c;

	va_start(va, n);
	for (i = 0; i < n; i++) {
		c = va_arg(va, char *);
		if (strcmp(s1, c) == 0) return true;
	}
	
	return false;
}

#endif
