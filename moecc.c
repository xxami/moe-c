
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

#include <util.h>

typedef enum {
	MainArgStateDefault,
	MainArgStateInput,
	MainArgStateOutput,
} main_arg_state;

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
			printf("%s%s\n", "moecc version :: c", GIT_REVISION);
			return 0;
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
				return 0;
			}
		}
	}

	printf("%s\n", "bye~");
	return 0;
}

