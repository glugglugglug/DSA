#include "stack.h"

void show_type(type_t type){
	if(type == INT){
		printf("int");
	}
	else if(type == FLOAT){
		printf("float");
	}
	else if(type == CHAR){
		printf("char");
	}
	else if(type == STRING){
		printf("string`");
	}
}
void show_data(data_t* data, type_t type){
	if(type == INT){
		printf("%d", data->data);
	}
	else if(type == FLOAT){
		printf("%f", data->data);
	}
	else if(type == CHAR){
		printf("%c", data->data);
	}
	else if(type == STRING){
		printf("%s", data->data);
	}
}
void init(stack_t* st){
	st->top = NULL;
}
int isempty(stack_t* st){
	if(st->top == NULL)
		return 1;
	return 0;
}
void push(stack_t* st, data_t data, type_t type){
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp->type = type;
	temp->data = data;
	temp->next = st->top;
	
	st->top = temp;
}
data_t pop(stack_t* st){
	if(isempty(st)){
		printf("Error - underflow\n");
		return NULL;
	}
	data_t popped = (data_t)malloc(sizeof(data_t));
	node_t* temp = top;

	popped = st->top->data;

	st->top = st->top->next;
	free(temp);

	return popped;
}
data_t peek(stack_t* st){
	if(isempty(st)){
		printf("Error - underflow\n");
		return NULL;
	}
	data_t popped = (data_t)malloc(sizeof(data_t));

	popped = st->top->data;

	return popped;
}
void show(stack_t* st){
	node_t* temp = st->top;

	while(temp != NULL){
		printf("data:type\n");
		show_data(temp->data,temp->type);
		printf(":");
		show_type(temp->temp);
		printf("\n");
		temp = temp->next;
	}
}
void clear(stack_t* st){
	node_t* temp1 = st->top;
	node_t* temp2 = st->top;

	while(temp1 != NULL){
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}
