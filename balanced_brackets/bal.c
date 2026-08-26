#include "bal.h"

void read(char* str){
	scanf("%[^\n]s", str);
}
void show_(char* str){
	printf("Given expression: %s\n",str);
}
int index_(char arr[], int size, char search){
	for(int i=0;i<size;i++){
		if(search == arr[i]){
			return i;
		}
	}
	return -1;
}
int check(char *str){
	stack* st = (stack*)malloc(sizeof(stack));
	init(st);
	char open[3] = {'(','{','['};
	char close[3] = {')','}',']'};
	
	while(*str != '\0'){
		char s = *str;
		int ind;
		if ((ind = index_(open,3,s)) > -1){
			push(st,open[ind]);
		}
		else if((ind = index_(close,3,s)) > -1){
			if(index_(open,3,pop(st)) != ind){
				return 0;
			}
		}
		s = *str++;
	}
	if(isempty(st)){
		return 1;
	}
	else{
		return 0;
	}
	free_stack(st);
}
