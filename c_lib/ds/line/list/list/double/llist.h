#ifndef LLIST_H__
#define LLIST_H__

#define INS_FORWARD 1
#define INS_BACKWARD 2
// TARGET: first we need a base struct as the usual node type
typedef struct LLIST_NODE_ST
{
    void *data;
    LLIST_NODE_ST *next;
    LLIST_NODE_ST *prev;
} LLIST_NODE;


// TARGET: we need a head struct to be the handle type for user
typedef struct LLIST_ST
{
    int size;
    LLIST_NODE head;
} LLIST;

// create head node of link list
LLIST *llist_create(int);

// insert
int llist_insert(LLIST *, void *, int mode);

// find
void *llist_find(LLIST *, void *key, void *cmp);

// update
int llist_update(LLIST *, void *key, void *change);

// del
int llist_del(LLIST *, void *key, void *cmp);

// fetch
int llist_fetch(LLIST *, void *key, void *cmp);

// show
void llist_show(LLIST *, void *show);

// destroy link list
void llist_destroy(LLIST *);

#endif