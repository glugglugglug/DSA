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
	if(temp != NULL){
		while(temp->next != NULL){
			disp_term(&temp->term);
			printf(" + ");
			temp = temp->next;
		}
		disp_term(&temp->term);
	}
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

float eval(list_t* list, int x){
	node_t* temp = list->head;
	int i; 
	float prod = 1, sum = 0;

	while(temp != NULL){
		prod = 1;
		for(i=0;i<temp->term.exp;i++){
			prod *= x;
		}
		sum += temp->term.coeff * prod;
		temp = temp->next;
	}
	return sum;
}
void copy(list_t* list1, list_t* list2){
	node_t* temp1 = list1->head;
	node_t* temp2 = (node_t*)malloc(sizeof(node_t));
	temp2->next = NULL;
	list2->head = temp2;

	node_t* newNode; 

	while(temp1 != NULL){
		newNode = (node_t*)malloc(sizeof(node_t));
		newNode->term = temp1->term;
		newNode->next = NULL;

		temp2->next = newNode;
		temp2 = newNode;

		temp1 = temp1->next;
	}
}
void differentiate(list_t* list1, list_t* list2){
	node_t* temp1 = list1->head;
	node_t* temp2 = (node_t*)malloc(sizeof(node_t));
	node_t* newNode;

	temp2->term.coeff = temp1->term.coeff * (temp1->term.exp);
	temp2->term.exp = (temp1->term.exp - 1);
	temp2->next = NULL;
	list2->head = temp2;
	
	temp1 = temp1->next;

	while(temp1 != NULL){
		if(temp1->term.exp != 0){
			newNode = (node_t*)malloc(sizeof(node_t));

			newNode->term.coeff = temp1->term.coeff * (temp1->term.exp);
			newNode->term.exp = (temp1->term.exp - 1);

			newNode->next = NULL;

			temp2->next = newNode;
			temp2 = newNode;

			temp1 = temp1->next;
		}
	}
}
float definite_integration(list_t* list1, list_t* list2, int upper, int lower){
	// doesnt work because struct is int :heart_eyes: 
	// node_t* temp1 = list1->head;
	// node_t* temp2 = (node_t*)malloc(sizeof(node_t));
	// node_t* newNode;

	// temp2->term.coeff = temp1->term.coeff / (temp1->term.exp + 1);
	// temp2->term.exp = (temp1->term.exp + 1);
	// temp2->next = NULL;
	// list2->head = temp2;
	// 
	// temp1 = temp1->next;

	// while(temp1 != NULL){
	// 	if(temp1->term.exp != 0){
	// 		newNode = (node_t*)malloc(sizeof(node_t));

	// 		newNode->term.coeff = temp1->term.coeff / (temp1->term.exp + 1);
	// 		newNode->term.exp = (temp1->term.exp + 1);

	// 		newNode->next = NULL;

	// 		temp2->next = newNode;
	// 		temp2 = newNode;

	// 		temp1 = temp1->next;
	// 	}
	// }
	// return eval(list2,upper) - eval(list2,lower); 
	
	node_t* temp = list1->head;
	int i;
	float prod_u = 1, prod_l = 1, sum = 0;

	while(temp != NULL){
		for(i=0;i<temp->term.exp+1;i++){
			prod_u *= upper;
			prod_l *= lower;
		}
		sum += (temp->term.coeff * (temp->term.exp + 1) * (prod_u - prod_l));
		temp = temp->next;
	}
	return sum;
}
