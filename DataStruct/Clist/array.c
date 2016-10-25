#include <stdio.h>
#include <stdlib.h>
#include "array.h"

struct Node
{
    struct Node*    next;
    ElementType     value;
};

int insert_list(List root, ElementType new_value)
{
    pNode current;
    pNode new_node;
    pNode previou_node;

    current = *root;
    previou_node = NULL;

    while(current!=NULL && current->value < new_value)
    {
        previou_node = current;
        current=current->next;
    }

    //previou_node = (pNode)malloc(sizeof(Node));
    new_node = (pNode)malloc(sizeof(Node));
    if(new_node == NULL)
        return FALSE;

    new_node->value = new_value;
    new_node->next = current;
    if(previou_node == NULL)
        *root = new_node;
    else
        previou_node->next = new_node;

    return TRUE;
}

void init_list(List root, ElementType value)
{
    root->next=NULL;
    root->value=value;
}

Position search_list(List root, ElementType value)
{
    pNode current;
    current = root;
    while(current != NULL )
    {
        if (current->value == value)
        {
            printf("Find value(%d) in list.\n",value);
            return current;
        }
        current=current->next;
    }

    printf("Find nothing.\n");
    return NULL;
}
