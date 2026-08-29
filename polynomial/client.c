#include "list.h"

int main(){
	int c, e, n, i;
	list_t poly;

	init(&poly);

	printf("Enter number of terms: ");
	scanf("%d", &n);

	for(i=0;i<n;i++){
		printf("Enter coefficient and exponent of term %d: ",(i+1));
		scanf("%d %d",&c,&e);
		insert(&poly,c,e);
	}
	disp_list(&poly);
	free_list(&poly);

	return 0;
}
