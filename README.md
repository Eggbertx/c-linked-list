# c-linked-list
A simple implementation of a doubly linked list

## Usage
See src/main.c

## Building/using llist as a shared object
```
make build-list
LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH ./llist
```

## Building/using llist as a static library
```
make build-staticlib
cc -o llist src/main.c libllist.a
```