#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef int ElementType;

typedef struct Node* pNode;
typedef pNode List;
typedef pNode Position;

#define FALSE   0
#define TRUE    1

int insert_list(List root, ElementType new_value);
Position search_list(List root, ElementType value);

int is_empty(List root);

void init_list(List root, ElementType value);

#endif // _ARRAY_H_
