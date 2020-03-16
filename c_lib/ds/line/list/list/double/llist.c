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
int llist_insert(LLIST *handler, void *node, int mode)
{

}

// show
void llist_show(LLIST *handler, void *show)
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








