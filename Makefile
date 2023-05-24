all: build/main
build/main: build/error.o build/hash.o build/board.o
	gcc -Iinc src/main.c -o build/main build/error.o build/hash.o build/board.o -Wall -Wpedantic
build/board.o:
	gcc -c -Iinc src/board.c -o build/board.o -Wall -Wpedantic
build/hash.o:
	gcc -c -Iinc src/hash.c -o build/hash.o -Wall -Wpedantic
build/error.o:
	gcc -c -Iinc src/error.c -o build/error.o -Wall -Wpedantic
clean:
	rm build/main build/error.o build/hash.o build/board.o

