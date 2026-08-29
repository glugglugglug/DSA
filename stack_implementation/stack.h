#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdio.h>

union data{
	//comment the types you dont need i suppose
	int data;
	float data;
	char data;
	char data[200]; 
};
typedef union data data_t;

enum type{
	INT, FLOAT, CHAR, STRING
}
typedef enum type type_t;

struct node{
	type_t type;
	data_t data;
	node* next;
};
typedef struct node node_t;

struct stack{
	node_t* top;
};
typedef struct stack stack_t;

void show_type(type_t);
void show_data(data_t*, type_t);
void init(stack_t*);
int isempty(stack_t*);
void push(stack_t*, data_t);
data_t pop(stack_t*);
data_t peek(stack_t*);
void show(stack_t*);
void clear(stack_t*);

#endif
