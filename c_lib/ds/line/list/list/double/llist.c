#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "llist.h"

// creeate
LLIST *llist_create(int size)
{
    LLIST *handler;
    handler = malloc(sizeof(LLIST));
    handler->size = size;
    handler->head.data = NULL;

    handler->head.prev = &handler->head;
    handler->head.next = &handler->head;

    return handler;
}

// insert
int llist_insert(LLIST *handler, void *data, int mode)
{
    LLIST_NODE *node = malloc(sizeof(LLIST_NODE));
    node->data = malloc(handler->size);
    memcpy(node->data, data, handler->size);
    
    if(mode == 1){
        node->prev = &handler->head;
        node->next = handler->head.next;
    } else if(mode == 2){
        node->prev = handler->head.prev;
        node->next = &handler->head;
    } else {
        return -1;
    }
    node->prev->next = node;
    node->next->prev = node;
    return 0;
}

// delete
int llist_del(LLIST *handler, void *key, llist_call_cmp *cmp)
{
    LLIST_NODE *cur;
    for(cur = handler->head.next; cur != &handler->head; cur = cur->next){
        if(!cmp(key, cur->data)){

            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur->data);
            free(cur);

            return 0;
        }
    }
}

// fetch
int llist_fetch(LLIST *handler, void *key, llist_call_cmp *cmp, void **data)
{
    LLIST_NODE *cur;
    for(cur = handler->head.next; cur != &handler->head; cur = cur->next){
        if(!cmp(key, cur->data)){
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free(cur);
            *data = cur->data;

            return 0;
        }
    }
}

// update
int llist_update(LLIST *handler, void *src, void *tar, llist_call_cmp *cmp, llist_call_op *update)
{
    LLIST_NODE *cur;
    for(cur = handler->head.next; cur != &handler->head; cur = cur->next){
        if(!cmp(src, cur->data)){
            update(cur->data, tar);
            return 0;
        }
    }
    return -1;
}

// find
void *llist_find(LLIST *handler, void *key, llist_call_cmp *cmp)
{
    LLIST_NODE *cur;
    for(cur = handler->head.next; cur != &handler->head; cur = cur->next){
        if(!cmp(key, cur->data)){
            return 0;
        }
    }
    return -1;
}

// show
void llist_show(LLIST *handler, llist_call_show *show)
{
    LLIST_NODE *cur = handler->head.next;
    for (; cur != &handler->head; cur = cur->next)
    {
        show(cur->data);
    }
}




// destroy
void llist_destroy(LLIST *handler)
{
    LLIST_NODE *cur, *next;
    for (cur = handler->head.next; cur != &handler->head; cur = next)
    {
        next = cur->next;
        free(cur->data);
        free(cur);
    }
    free(handler);
}   








