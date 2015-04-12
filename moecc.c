
#ifdef __STDC_NO_VLA__
	#error No VLA support
#endif

#ifndef GIT_REVISION
	#define GIT_REVISION "unknown"
#endif

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

typedef enum {
	MainArgStateDefault,
	MainArgStateInput,
	MainArgStateOutput,
} main_arg_state;

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

/**
 * moecc
 * [-v | --version]
 * [-f | -i | --input file1.moe file2.cc file3.mc file4.moec ..]
 * [-o | --output out.c]
 */
int main(int argc, char *argv[]) {
	int i;
	main_arg_state state = MainArgStateDefault;

	for (i = 1; i < argc; i++) {
		if (strcmp_m(argv[i], 2, "-v", "--version")) {
			printf("%s%s\n", "moecc version :: ", GIT_REVISION);
		}
		else if (strcmp_m(argv[i], 3, "-f", "-i", "--input")) {
			state = MainArgStateInput;
		}
		else if (strcmp_m(argv[i], 2, "-o", "--output")) {
			state = MainArgStateOutput;
		}
		else {
			if (state == MainArgStateInput) {
				printf("%s%s\n", "input :: ", argv[i]);
			}
			else if (state == MainArgStateOutput) {
				printf("%s%s\n", "output :: ", argv[i]);
			}
			else {
				printf("%s%s\n", "invalid arg :: ", argv[i]);
			}
		}
	}

	printf("%s", "bye~\n");
	return 0;
}

