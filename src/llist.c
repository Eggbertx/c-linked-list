#include <stdio.h>
#include <stdlib.h>

#include "llist.h"

llist* llist_create(int val) {
	llist* list = (llist*)malloc(sizeof(llist*));
	list->prev = NULL;
	list->next = NULL;
	list->value = val;
	return list;
}

void llist_destroy(llist* list, int recursive) {
	if(recursive && list->prev != NULL) {
		llist_destroy(list->prev, recursive);
		free(list->prev);
		list->prev = NULL;
	}

	if(recursive && list->next != NULL) {
		llist_destroy(list->next, recursive);
		free(list->next);
		list->next = NULL;
	}
	free(list);
}

int llist_length(llist* list) {
	llist* _next = list;
	int i = 0;
	while(_next != NULL) {
		_next = _next->next;
		i++;
	}
	return i;
}

llist* llist_at(llist* list, int at) {
	int i = 0;
	llist* current = list;
	while(i++ < at) {
		if(current->next == NULL) return NULL;
		current = current->next;
	}
	return current;
}

llist* llist_foreach(llist* list, void (*func)(int,llist*)) {
	llist* _next = list;
	int i = 0;

	while(_next != NULL) {
		if(func != NULL)
			(*func)(i++, _next);
		_next = _next->next;
	}

	return _next;
}

llist* llist_head(llist* list) {
	// TODO
	return NULL;
}

llist* llist_end(llist* list) {
	return llist_foreach(list, NULL);
}

llist* llist_insert(llist* list, int pos, int val) {
	llist* at = llist_at(list, pos);
	llist* oldnext = at->next;
	llist* newnext = llist_create(val);
	newnext->next = oldnext;
	newnext->prev = at;
	at->next = newnext;
	return at->next;
}

llist* llist_push(llist* list, int val) {
	llist* end = list;
	while(end->next != NULL) {
		end = end->next;
	}

	end->next = (llist*)malloc(sizeof(llist*));
	end->next->prev = end;
	end->next->value = val;
	return end->next;
}

void llist_print(int i, llist* link) {
	if(link == NULL) return;
	printf("list[%d]: %d\n", i, link->value);

	if(i > 0)
		printf("\tlist[%d]->prev: %d\n", i, (int)(link->prev->value));
	if(link->next != NULL)
		printf("\tlist[%d]->next: %d\n", i, (int)(link->next->value));
}