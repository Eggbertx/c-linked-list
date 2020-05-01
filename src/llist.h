#ifndef LLIST_H
#define LLIST_H

typedef struct llist {
	int value;
	struct llist* prev;
	struct llist* next;
} llist;
typedef struct llist llist;

llist* llist_create(int val); /* , llist_type type); */

void llist_destroy(llist* list, int recursive);

int llist_length(llist* list);

llist* llist_at(llist* list, int at);

llist* llist_foreach(llist* list, void (*func)(int,llist*));

llist* llist_head(llist* list);

llist* llist_end(llist* list);

llist* llist_insert(llist* list, int pos, int val);

llist* llist_push(llist* list, int val);

void llist_print(int i, llist* link);

#endif