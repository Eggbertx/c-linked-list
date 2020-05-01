BIN=llist
SRC=src/main.c src/llist.c
CFLAGS=-Wall -pedantic

build:
	cc -o ${BIN} ${CFLAGS} ${SRC}

build-debug:
	cc -o ${BIN} ${CFLAGS} -g ${SRC}

build-lib:
	cc -shared -o ${BIN}.so ${CFLAGS} src/llist.c

build-staticlib:
	$(error TODO)

clean:
	rm -f ${BIN}*
	rm -f *.o
	rm -f *.s