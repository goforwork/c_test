#ifndef HEAD_LIST_H__
#define HEAD_LIST_H__

// type of each node
typedef int datatype;

// each node of list
typedef struct node_st{
    datatype data;
    struct node_st *next;
} head_list;

// create head node for a node
head_list *hl_create();

// insert
int hl_insert_at(head_list *, int, head_list *);

// delete the first of a list
int hl_del(head_list *);

// update
int hl_update(head_list *, datatype *, datatype *);

// find
int hl_find(head_list *, datatype *, head_list **target);

// show
void hl_show(head_list *);

// count
int hl_count(head_list *);

// is empty
int hl_isEmpty(head_list *list);

// destory a list
void hl_destroy(head_list *);

#endif