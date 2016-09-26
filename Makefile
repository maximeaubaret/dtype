
build: main.o
	cc build/*.o -o build/dtype

main.o:
	cc -c src/main.c -o build/main.o

clean:
	rm build/*

install: build
	cp build/dtype /usr/local/bin

uninstall:
	-rm /usr/local/bin/dtype
