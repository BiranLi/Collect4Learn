#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main()
{
    printf("Trace into main!\n");

    pNode root;
    root = (pNode)malloc(sizeof(Node));
    init_list(&root,1);
    if(TRUE!=insert_list(&root,2))
    {
        printf("Insert failed.\n");
        return 1;
    }

    pNode tmp;
    tmp = search_list(&root,1);
    if (tmp != NULL)
        printf("Target value is %d.\n",tmp->value);

    free(root);
    return 0;
}
