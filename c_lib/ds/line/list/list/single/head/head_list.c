#include <stdio.h>
#include <stdlib.h>
#include "head_list.h"

// create
head_list *hl_create()
{
    head_list *head;
    head = malloc(sizeof(head_list));
    if(!head){
        return NULL;
    }
    head->next = NULL;
}

// insert
int hl_insert_at(head_list *list, int index, head_list *node)
{
    head_list *cur = list, *tar;
    int i = -1;
    tar = malloc(sizeof(head_list));
    tar->data = node->data;
    tar->next = NULL;

    while (cur != NULL && i < index){
        if(i == index - 1){
            tar->next = cur->next;
            cur->next = tar;
            return 0;
        }
        cur = cur->next;
        i++;
    }
    
    return -1;
}

// delete
int hl_del(head_list *list)
{
    if(list == NULL || list->next == NULL){
        return -1;
    }
    head_list *tar = list->next;
    list->next = tar->next;
    free(tar);
    return 0;
}

// update
int hl_update(head_list *list, datatype *pre, datatype *next)
{
    if(hl_count(list) < 1){
        return -1;
    }
    for(list = list->next; list != NULL; list = list->next){
        if(list->data == *pre){
            list->data = *next;
            return 0;
        }
    }
    return 1;
}

// find
int hl_find(head_list *list, datatype *node, head_list **target)
{
    if(hl_count(list) < 1){
        return -1;
    }
    for (list = list->next; list != NULL; list = list->next){
        if(list->data == *node){
            *target = list;
            return 0;
        }
    }
    return -2;
}
// show
void hl_show(head_list *list)
{
    if(list == NULL || list->next == NULL){
        return;
    }
    head_list *cur; 
    for(cur = list->next; cur != NULL; cur = cur->next){
        printf("%d ", cur->data);
    }
    printf("\n");
}

// count
int hl_count(head_list *list)
{
    int count = 0;
    for(list = list->next; list != NULL; list = list->next){
        count++;
    }
    return count;
}

// destroy
void hl_destroy(head_list *list)
{
    if(list == NULL){
        return;
    }
    head_list *next, *cur;
    for(cur = list; cur != NULL; cur = next){
        next = cur->next;
        free(cur);
    }
    return;
}