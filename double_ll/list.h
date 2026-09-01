#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};
typedef struct node node_t;

struct d_list{
	node_t* head;
};
typedef struct d_list d_list_t;

void init(d_list_t*);
void insert_node(d_list_t*, int, int);
void delete_node(d_list_t*, int);
void add_after_key(d_list_t*, int, int);
void add_before_key(d_list_t*, int, int);
void disp_list(d_list_t*);
void remove_key(d_list_t*, int);

void free_list(d_list_t*);

#endif
