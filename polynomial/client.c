#include "list.h"

int main(){
	int c, e, n, i, x, u, l;
	list_t poly;
	list_t diff_poly;
	list_t intg_poly;

	init(&poly);
	init(&diff_poly);
	init(&intg_poly);

	printf("Enter number of terms: ");
	scanf("%d", &n);

	for(i=0;i<n;i++){
		printf("Enter coefficient and exponent of term %d: ",(i+1));
		scanf("%d %d",&c,&e);
		insert(&poly,c,e);
	}
	disp_list(&poly);

	printf("Enter number to evaluate it with: ");
	scanf("%d",&x);
	printf("Evaluated to : %f\n",eval(&poly,x));
	disp_list(&poly);
	printf("Differentiated: ");
	differentiate(&poly,&diff_poly);
	disp_list(&diff_poly);

	printf("Enter upper and lower bound for integration: ");
	scanf("%d %d",&u,&l);

	printf("Ans : %f\n",definite_integration(&poly,&intg_poly,u,l));

	disp_list(&intg_poly);


	free_list(&poly);

	return 0;
}
