#include "stack.h"

void init(stack* st){
	st->top = NULL;
}
int isempty(stack* st){
	if(st->top == NULL){
		return 1;
	}
	return 0;
}
void push(stack* st, char data){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	newNode->data = data;
	newNode->next = st->top;

	st->top = newNode;
}
char pop(stack *st){
	if(isempty(st)){
		printf("error- stack empty\n");
		return '\0';
	}
	char data_popped = st->top->data;
	node_t* temp = st->top;
	st->top = st->top->next;
	free(temp);
	return data_popped;
}
char peek(stack *st){
	if(isempty(st)){
		printf("error- stack empty\n");
		return '\0';
	}
	return st->top->data;
}
void show(stack *st){
	node_t* temp = st->top;
	while(temp != NULL){
		printf("%c ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void free_stack(stack* st){
	node_t* temp1 = st->top;
	node_t* temp2;
	while(temp1 != NULL){
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}
