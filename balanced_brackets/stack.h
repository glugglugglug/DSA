#include <stdlib.h>
#include <stdio.h>

#ifndef STACK_H
#define STACK_H

struct node{
	char data;
	struct node *next;
};
typedef struct node node_t;

struct stack{
	node_t *top;
};
typedef struct stack stack;

void init(stack* st);
int isempty(stack* st);
void push(stack* st, char data);
char pop(stack* st);
char peek(stack* st);
void show(stack* st);
void free_stack(stack* st);

#endif
