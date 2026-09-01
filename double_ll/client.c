#include "list.h"

int main(){
	int ch = 0;
	int dat, loc, key;
	d_list_t list;
	
	init(&list);

	do{
		printf("1 : insert node\n2 : delete node\n3 : add after key\n4 : add before key\n5 : remove key\n6 : display list\n");
		printf("enter choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("enter data and location: ");
				scanf("%d %d",&dat,&loc);
				insert_node(&list,dat,loc);
				break;
			case 2:
				printf("enter location: ");
				scanf("%d",&loc);
				delete_node(&list,loc);
				break;
			case 3:
				printf("enter data and key: ");
				scanf("%d %d",&dat,&key);
				add_after_key(&list,dat,key);
				break;
			case 4:
				printf("enter data and key: ");
				scanf("%d %d",&dat,&key);
				add_before_key(&list,dat,key);
				break;
			case 5:
				printf("enter key: ");
				scanf("%d",&key);
				remove_key(&list,key);
				break;
			case 6:
				disp_list(&list);
				break;
			default:
				ch = 0;
				break;
		}
	}while(ch != 0);
	
	free_list(&list);

	return 0;
}
