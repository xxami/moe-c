
cc=gcc
cdefs=-DGIT_REVISION=$(git describe --tags --always)
cflags=-Wall -std=c99 -I $(cdefs)

always:
	echo compile flags: $(cdefs)
	$(cc) $(cflags) moecc.c -o moecc

