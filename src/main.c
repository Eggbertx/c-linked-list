#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char** argv) {
 	llist* list;

	list = llist_create(0);
	llist_push(list, 2);
	llist_push(list, 4);
	printf("Inserting 1 into list[1]\n");
	llist_insert(list, 1, 1); // should be 0,1,2,4
	llist_foreach(list, llist_print);
	printf("list size: %d\n", llist_length(list));
	int i = 0;
	llist* at = llist_at(list, i); // greater than length
	if(at == NULL) printf("list[%d] == NULL\n", i);
	else printf("list[%d] = %d\n", i, at->value);

	// llist* end = llist_end(list);
	// printf("list end: %d", end->value);
	// llist_destroy(list, 1);
	return 0;
}
