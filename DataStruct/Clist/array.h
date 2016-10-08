#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef int Elemtype;

typedef struct NODE{
    struct NODE*    next;
    Elemtype        value;
} Node, *pNode;

#define FALSE   0
#define TRUE    1

int insert_list(pNode *root, Elemtype new_value);
pNode search_list(pNode *root,Elemtype value);

void init_list(pNode *root, Elemtype value);

#endif // _ARRAY_H_
