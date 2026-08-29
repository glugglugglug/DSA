#ifndef LIST_H
#define LIST_H

#include "term.h"

#include <stdio.h>
#include <stdlib.h>

struct node{
	term_t term;
	struct node* next;
};
typedef struct node node_t;

struct list{
	node_t* head;
};
typedef struct list list_t;

void init(list_t*);
void insert(list_t*, int, int);
void disp_list(list_t*);
void free_list(list_t*);

#endif
