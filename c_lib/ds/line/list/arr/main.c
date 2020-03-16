#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

// func main is in order to test this module
int main() {
	printf("start\n");
	sqlist *list;
	sqlist *list1;
	datatype src[] = {12, 23, 34, 45};
	datatype src1[] = {45, 56, 78};
	
	
	list = sqlist_create();
	if(!list){
		return 1;
	}

	sqlist_create1(&list1);
	if(!(list1)){
		return 1;
	}

	int i;
	for(i = 0; i < sizeof(src)/sizeof(*src); i++){
		sqlist_insert(list, 0, &(src[i]));
	}
	for(i = 0; i < sizeof(src1) / sizeof(*src1); i++){
		sqlist_insert(list1, 0, &(src1[i]));
	}
	
	// sqlist_del(list, 1);
	int tar = 23;
	// sqlist_update(list, 2, &tar);

	// printf("%d\n", sqlist_find(list, &tar));

	printf("%d\n", sqlist_getnum(list));

	sqlist_display(list);
	// sqlist_display(list1);

	sqlist_destroy(list);
	sqlist_destroy(list1);

	printf("\nend");

	return 0;
}
