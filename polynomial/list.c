#include "list.h"

void init(list_t* list){
	list->head = NULL;
}
void insert(list_t* list, int coeff, int exp){
	node_t* newNode = (node_t*)malloc(sizeof(node_t));
	node_t* temp = list->head;
	set_term(&newNode->term, coeff, exp);
	newNode->next = NULL;

	if(list->head == NULL || compare_exponents(&list->head->term,&newNode->term)<0){
		newNode->next = list->head;
		list->head = newNode;
	}
	else{
		while(temp != NULL){
			if(temp->next == NULL || compare_exponents(&temp->next->term,&newNode->term)<0){
				newNode->next = temp->next;
				temp->next = newNode;
				break;
			}
			temp = temp->next;
		}
	}
}
void disp_list(list_t* list){
	node_t* temp = list->head;
	printf("polynomial = ");
	while(temp->next != NULL){
		disp_term(&temp->term);
		printf(" + ");
		temp = temp->next;
	}
	disp_term(&temp->term);
	printf("\n");
}
void free_list(list_t* list){
	node_t* temp1 = list->head;
	node_t* temp2 = temp1;

	while(temp1 != NULL){
		temp2 = temp1->next;
		free(temp1);
		temp1 = temp2;
	}
}
