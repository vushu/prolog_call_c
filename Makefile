all: lib main

main:
	swipl -o main -g main -c main.pl

lib:
	swipl-ld -v -shared -o foo foo.c

clean:
	rm -rf main foo.o foo.so
