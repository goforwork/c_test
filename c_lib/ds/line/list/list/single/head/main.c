#include <stdio.h>
#include <stdlib.h>
#include "head_list.h"

int main()
{
    head_list *list;
    list = hl_create();

    head_list data_src[] = {{0, NULL}, {1, NULL}, {2, NULL}};
    int i;
    for ( i = 0; i < sizeof(data_src) / sizeof(*data_src); i++)
    {
        if(hl_insert_at(list, 0, &(data_src[i]))){
            exit(1);
        }
    }
    
    // if(hl_del(list)){
    //     printf("fail");
    // }

    // datatype pre = 1, next = 121;
    // hl_update(list, &pre, &next);

    // datatype tar = 1;
    // head_list *res;
    // hl_find(list, &tar, &res);
    // printf("%d\n", res->data);

    hl_show(list);

    hl_destroy(list);
}