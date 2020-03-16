#ifndef SQLIST_H__
#define SQLIST_H__

// maxsize of list
#define DATASIZE 1024

// type in list
typedef int datatype;

// structure
typedef struct node_st
{
	datatype data[DATASIZE];
	int last;
} sqlist;

// creare
sqlist *sqlist_create();

void sqlist_create1(sqlist **);

// insert
int sqlist_insert(sqlist *, int, datatype *);

// delete
int sqlist_del(sqlist *, int);

// update
int sqlist_update(sqlist *, int, datatype *);

// find 
int sqlist_find(sqlist *, datatype *);

// set empty
int sqlist_setEmpty(sqlist *);

// check empty
int sqlist_isEmpty(sqlist *);

// count
int sqlist_getnum(sqlist *);

// union
sqlist *sqlist_union(sqlist *, sqlist *); 

// display
void sqlist_display(sqlist *);

// destroy 
void sqlist_destroy(sqlist *);

#endif
	
