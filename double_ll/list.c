#include "list.h"

void init(d_list_t* list){
	list->head = NULL;
}
void insert_node(d_list_t* list, int data, int loc){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	node_t* temp;
	int i;

	newNode->prev = NULL;
	newNode->next = NULL;

	newNode->data = data;

	if(loc == 1){
		if(list->head != NULL){
			newNode->next = list->head;
			list->head->prev = newNode;
		}
		list->head = newNode;
	}
	else{
		temp = list->head;
		for(i=1;i<loc-1;i++){
			if(temp == NULL){
				printf("Location out of bounds !!!\n");
				return;
			}
			temp = temp->next;
		}
		newNode->next = temp->next;
		if(temp->next != NULL){
			temp->next->prev = newNode;
		}
		temp->next = newNode;
		newNode->prev = temp;
	}
}
void delete_node(d_list_t* list, int loc){
	node_t* temp = list->head;
	int i;

	if(loc == 1 && list->head != NULL){
		list->head = list->head->next;
		free(temp);
		list->head->prev = NULL;

	}
	else{
		for(i=1;i<loc-1;i++){
			if(temp == NULL){
				printf("Location out of bounds !!!\n");
				return;
			}
			temp = temp->next;
		}

		if(temp->next != NULL){
			temp->next->prev = temp->prev;
		}
		if(temp->prev != NULL){
			temp->prev->next = temp->next;
		}
		free(temp);
	}
}
void add_after_key(d_list_t* list, int data, int key){
	node_t* temp = list->head;
	int i = 1;
	int flag = 0;

	while(temp != NULL && flag == 0){
		if(temp->data == key){
			insert_node(list, data, i+1);
			flag = 1;
		}
		temp = temp->next;
		i++;
	}
	if(flag == 0){
		printf("key not found\n");
	}
}
void add_before_key(d_list_t* list, int data, int key){
	node_t* temp = list->head;
	int i = 1;
	int flag = 0;

	while(temp != NULL && flag == 0){
		if(temp->data == key){
			insert_node(list, data, i);
			flag = 1;
		}
		temp = temp->next;
		i++;
	}
	if(flag == 0){
		printf("key not found\n");
	}
}
void remove_key(d_list_t* list, int key){
	node_t* temp = list->head;
	int i = 1;
	int flag = 0;

	while(temp != NULL){
		if(temp->data == key){
			delete_node(list, i+1);
			flag = 1;
		}
		temp = temp->next;
		i++;
	}
	if(flag == 0){
		printf("key not found\n");
	}
}
void disp_list(d_list_t* list){
	node_t* temp = list->head;

	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
	
void free_list(d_list_t* list){
	node_t* temp1 = list->head;
	node_t* temp2 = temp1;

	while(temp1 != NULL){
		temp2=temp1;
		temp1 = temp1->next;
		free(temp2);
	}
}
