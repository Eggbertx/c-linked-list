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
	llist *tmp = list->next;
	llist* tmp2;
	while(tmp && recursive) {
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	tmp = list->prev;
	while(tmp && recursive) {
		tmp2 = tmp;
		tmp = tmp->prev;
		free(tmp2);
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
	llist* current = list;
	while(current->prev != NULL) {
		current = current->prev;
	}
	return current;
}

llist* llist_end(llist* list) {
	llist* current = list;
	while(current->next != NULL) {
		current = current->next;
	}
	return current;
}

llist* llist_insert(llist* list, int pos, int val) {
	llist* oldat = llist_at(list, pos);
	llist* newat = llist_create(val);
	newat->prev = oldat->prev;
	newat->next = oldat;
	oldat->prev->next = newat;
	oldat->prev = newat;

	return newat;
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
