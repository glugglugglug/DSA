#include "bal.h"

int main(){
	char exp[200];
	printf("Enter an expression: ");
	read(exp);
	show_(exp);
	if(check(exp)){
		printf("brackets r balanced\n");
	}
	else{
		printf("brackets r not balanced\n");
	}
	return 0;
}
