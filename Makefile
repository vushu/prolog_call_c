all: raylib-swi main
CC = swipl-ld
CFLAGS =-shared $$(pkg-config --libs --cflags raylib)

main:
	swipl -o main -g main -c main.pl

lib:
	swipl-ld -v -shared -o foo foo.c

raylib-swi:
	$(CC) -g -fPIC foo.c $(CFLAGS) -o foo lib/libraylib.so


clean:
	rm -rf main foo.o foo.so
