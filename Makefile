BIN=llist
SRC=src/main.c src/llist.c

build:
	cc -o ${BIN} ${SRC}

build-debug:
	cc -o ${BIN} -g ${SRC}

build-lib:
	cc -shared -o ${BIN}.so src/llist.c

build-staticlib:
	$(error TODO)

clean:
	rm -f ${BIN}*
	rm -f *.o
	rm -f *.s