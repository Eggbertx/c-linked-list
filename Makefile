CC=cc
BIN=llist
SRC=src/main.c src/llist.c
CFLAGS=-Wall -pedantic

build:
	${CC} -o ${BIN} ${CFLAGS} ${SRC}

build-debug:
	${CC} -o ${BIN} ${CFLAGS} -g ${SRC}

build-lib:
	${CC} -c ${CFLAGS} src/llist.c
	${CC} -shared -o lib${BIN}.so ${BIN}.o
	rm -f ${BIN}.o

build-staticlib:
	${CC} -c src/llist.c
	ar rcs libllist.a llist.o
	rm -f ${BIN}.o

clean:
	rm -f ${BIN}*
	rm -f lib${BIN}*
	rm -f src/*.o
	rm -f *.o
	rm -f src/*.s