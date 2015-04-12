
cc=gcc
cdefs=-DGIT_REVISION=\"$(shell git describe --tags --always)\"
cflags=-Wall -std=c99 -I. $(cdefs)

always:
	$(cc) $(cflags) moecc.c -o moecc

