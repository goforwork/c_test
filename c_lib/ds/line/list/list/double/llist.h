#ifndef LLIST_H__
#define LLIST_H__

#define INS_FORWARD 1
#define INS_BACKWARD 2
// TARGET: first we need a base struct as the usual node type
typedef struct LLIST_NODE_ST
{
    void *data;
    struct LLIST_NODE_ST *next;
    struct LLIST_NODE_ST *prev;
} LLIST_NODE;


// TARGET: we need a head struct to be the handle type for user
typedef struct LLIST_ST
{
    int size;
    LLIST_NODE head;
} LLIST;

// callback:show
typedef void llist_call_show(void *);
typedef void llist_call_op(void *, void *);

// callback:compare
typedef int llist_call_cmp(const void *, const void *);

// create head node of link list
LLIST *llist_create(int);

// insert
int llist_insert(LLIST *, void *, int mode);

// find
void *llist_find(LLIST *, void *src, void *tar, llist_call_cmp *cmp);

// update
int llist_update(LLIST *, void *key, void *change);

// del
int llist_del(LLIST *, void *key, llist_call_cmp *cmp);

// fetch
int llist_fetch(LLIST *, void *key, llist_call_cmp *cmp, void **data);

// show
void llist_show(LLIST *, llist_call_show *show);

// destroy link list
void llist_destroy(LLIST *);

#endif