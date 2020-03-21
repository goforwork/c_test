#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

typedef struct {
        int id;
        char name[32];
        int chinese;
        int math;
} stu_st;

// callback:show
void show(void *node_data)
{
    stu_st *data = node_data;
    printf("id:%d name:%s math:%d chinese:%d\n", data->id, data->name, data->math, data->chinese);
}

// callback:compare
int name_cmp(const void *name, const void *node)
{
    const char *p_name = name;
    const stu_st *p_node = node;
    return strcmp(p_name, p_node->name);
}

int main()
{
    
    LLIST *handler;

    // create
    handler = llist_create(sizeof(stu_st));
    if(!handler){
        printf("create failed");
        return -1;
    }

    int i;
    stu_st stu;
    for(i = 0; i < 7; i++){
        stu.id = i;
        snprintf(stu.name, 32, "stu%d", i);
        stu.math = rand() % 100;
        stu.chinese = rand() % 100;
        
        llist_insert(handler, &stu, INS_FORWARD);
    }

    if(llist_del(handler, &"stu4", name_cmp)){
        return -1;
    }

    void *ftc_data;
    if(llist_fetch(handler, &"stu5", name_cmp, &ftc_data)){
        return -1;
    }
    printf("\nfetch:");
    show((stu_st *)ftc_data);
    
    llist_show(handler, &show);

    // destroy
    llist_destroy(handler);
}