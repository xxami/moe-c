moecc=../moecc
cc=gcc
cdefs=-DGIT_REVISION=\"$(shell git describe --tags --always)\"
cflags=-Wall -std=c99 -I. $(cdefs)

always:
	$(moecc) --input moecc.moe --output out.c
	# $(cc) $(cflags) out.c -o moecc


