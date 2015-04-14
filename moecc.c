
#ifdef __STDC_NO_VLA__
	#error No VLA support
#endif

#ifndef GIT_REVISION
	#define GIT_REVISION "unknown"
#endif

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
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
	char *input = 0;
	char *output = 0;

	if (argc == 1) {
		printf("%s\n", "moecc [-v] [-f file.moe] [-o out.c] | man moecc");
		return 0;
	}
	for (i = 1; i < argc; i++) {
		if (strcmp_m(argv[i], 2, "-v", "--version")) {
			printf("%s%s\n", "moecc version :: c-", GIT_REVISION);
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
				if (input == 0) {
					input = argv[i];
				}
				else {
					printf("%s\n", "error :: more than one input");
				}
			}
			else if (state == MainArgStateOutput) {
				if (output == 0) {
					output = argv[i];
				}
				else {
					printf("%s\n", "error :: more than one output");
				}
			}
			else {
				printf("%s%s\n", "error :: invalid arg -> ", argv[i]);
				return 0;
			}
		}
	}	
	if (!input || !output) {
		printf("%s\n", "error :: missing input or output file");
		return 0;
	}
	else {
		/**
		 * safe to compile
		 */
		printf("compiling %s to %s... ", input, output);
		printf("%s\n", "done ~ bye!");
	}
	return 0;
}

