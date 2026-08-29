// using stack ig

#include "stack.h"

int main(){
	int choice = 0, i = 0, flag = 0;
	char data[200];
	type_t type;
	stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
	data_t temp_data = (data_t)malloc(sizeof(data_t));
	init(stack);

	do{
		printf("Stack options: \n");
		printf("1.PUSH\n");
		printf("2.POP\n");
		printf("3.PEEK\n");
		printf("4.EMPTY?\n");
		printf("5.SHOW STACK\n");
		printf("--- 0 to quit ---\n");

		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter data to be pushed\n");
				scanf("%[^\n]s",data);

				for(i = 0; data[i] != '\0';i++){
					if(flag == 0 && !( (int)data[i] > 47 && (int)data[i] <58)){
						flag = 1;
					}
					i++;
				}
				if(flag == 1){
					temp_data.data = data;
					type = STRING
				}
				else{
					temp_data.data = atoi(data);
					type = INT
				}
				push(stack, data, type);
				break;
			case 2:
				printf("Popped data: ");
				temp_data = pop(stack);
				show_data(temp
				break;


	}while(choice != 0);

	clear(st);
	return 0;
}
