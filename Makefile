
build: main.o
	cc build/*.o -o build/type

main.o:
	cc -c src/main.c -o build/main.o
