#include <stdio.h>
#include <stdlib.h>
#include "sqlist.h"

// create
sqlist *sqlist_create()
{
    sqlist *list;
	list = malloc(sizeof(*list));
    if(list == NULL){
        return NULL;
    }
    list->last = -1;
    return list;
};

void sqlist_create1(sqlist **list)
{
    *list = malloc(sizeof(**list));
    if(*list == NULL){
        return ;
    }
    (*list)->last = -1;
    return ;
};

int sqlist_insert(sqlist * list, int index, datatype *node)
{
    if(list->last >= DATASIZE - 1){
        return -1;
    }
    if(index > list->last + 1 || index < 0){
        return -1;
    }
    int i = list->last;
    for(;i >= index; i--){
        list->data[i + 1] = list->data[i];
    }
    list->data[index] = *node;
    list->last++;
    // printf("%d\n", list->last);
    return 0;
};

int sqlist_del(sqlist *list, int index)
{
    if(list->last < 0){
        return -1;
    }
    if(index > list->last || index < 0){
        return -1;
    }
    int i = index;
    for(;i <= list->last; i++){
        list->data[i] = list->data[i+1];
    }
    list->last--;
};

int sqlist_update(sqlist *list, int index, datatype *node)
{
    if(list->last < 0){
        return -1;
    }
    list->data[index] = *node;

};

int sqlist_find(sqlist *list, datatype *node)
{
    if(list->last < 0){
        return -1;
    }
    int i = 0;
    for(; i <= list->last; i++){
        if(list->data[i] == *node){
            return i;
        }
    }
    return -1;
};

int sqlist_isEmpty(sqlist *list)
{
    return list->last;
};

int sqlist_getnum(sqlist * list)
{
    return list->last + 1;
};

void sqlist_display(sqlist *list)
{
    int i;
    for(i = 0; i <= list->last; i++){
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

void sqlist_destroy(sqlist *list)
{
    free(list);
};