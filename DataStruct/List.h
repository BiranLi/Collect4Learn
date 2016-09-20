#ifndef _LIST_H_
#define _LIST_H_
struct Node;

typedef struct Node* pToNode;
typedef pToNode List;
typedef pToNode Position;

typedef int ElemType;

int IsEmpty(List L);
Position Find(ElemType X, List L);
void Delete(ElemType X, List L);
void Insert(ElemType X, List L, Position P);
void DeleteAll(List L);



#endif