#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
本段代码注意点
1.结构体中的指针操作的时候，需要提前给予内存分配
2.结构体中的柔性数组，在结构体指针创建的时候额外的分配内存
*/

char const *keyword[]={
    "do",
    "for",
    "if",
    "register",
    NULL
    };

char* const base_str="Hello for there,honey.";
char* const desire_word="for";

typedef struct Simple{
    int a;
    int b;
    char* c;
    char d[0];
}Simple;
Simple* Member;

int find_keyword(const char* desire_word, char const *keyword_table[]);
void cp_struct_simple(char* const desire_word);

int main()
{
    //printf("Hello world!\n");
/*  printf("size of key is %d.\n",sizeof(keyword));
    printf("first is %s,%s.\n",keyword[0],*keyword);
    printf("second is %s,%s.\n",keyword[1],*(keyword+1));

    const char* desire_word="for";
    int pos = find_keyword(desire_word,keyword);
    if(pos==-1)
    {
        return 1;
    }
*/

/*    char* last;
    last=strstr(base_str,desire_word);
    printf("pos_char* is %s,pos is %d.\n",last,last-base_str);//last-base_str is pos of desire_word
*/

    cp_struct_simple(desire_word);

    //memcpy(Member->c,desire_word,sizeof(desire_word));
    return 0;
}

int find_keyword(const char* desire_word, char const *keyword_table[])
{
    char const **kwp;
    int pos=-1;
    for(kwp = keyword_table;*kwp!=NULL;kwp++)
    {
        if(0==strcmp(*kwp,desire_word))
        {
            pos = kwp-keyword_table;
            printf("target position is %d.\n",kwp-keyword_table);
            break;
        }
    }

    return pos;
}

void cp_struct_simple(char* const desire_word)
{
    Member = (Simple*)malloc(sizeof(Simple)+sizeof(char)*4);//for array which length is 0, we need malloc its memory at first;
    memset(Member,0,sizeof(Simple));
    Member->c = (char*)malloc(4*sizeof(char));
    memset(Member->c,0,4*sizeof(char));
    //Member->d = malloc(4);
    strcpy(Member->c,desire_word);
    //memcpy(Member->d,desire_word,strlen(desire_word)+1);//strlen +1 will add \0 ch to the string
    strcpy(Member->d,desire_word);
    printf("Member has c %s.\n",Member->c);
    printf("Member has d %s.\n",Member->d);

    free(Member->c);
    Member->c=NULL;
    free(Member);
    Member=NULL;
}
