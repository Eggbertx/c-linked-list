#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main(int argc, char** argv) {
 	llist* list;
	int i = 1;
	llist* at;
	llist* head;
	llist* end;

	list = llist_create(1);
	llist_push(list, 2);
	llist_push(list, 3);

	printf("Inserting 4 into list[1]\n");
	llist_insert(list, 1, 4); // should be 1,4,2,3
	llist_foreach(list, llist_print);
	printf("list size: %d\n", llist_length(list));

	at = llist_at(list, i);
	if(at == NULL) printf("list[%d] == NULL\n", i);
	else printf("list[%d] = %d\n", i, at->value);

	head = llist_head(list);
	if(head == NULL) printf("list head == NULL\n");
	else printf("list head: %d\n", head->value);

	end = llist_end(list);
	if(end == NULL) printf("list end == NULL\n");
	else printf("list end: %d\n", end->value);
	llist_destroy(list, 1);
	return 0;
}
