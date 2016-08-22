#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    const char* FORMAT[5] = {"first",   
                             "second",
                             "third",
                             "fourth",
                             "fifth"};
    
    char *desire_word = "fifth";
    char **keyword;
    for (keyword = FORMAT; keyword < FORMAT+5; keyword++ )
    {
        if(0 == strcmp(desire_word, *keyword))
        {
            printf("Find desire string [%s],position [%d]",desire_word, keyword-FORMAT );
            system("pause");
            return 0;
        }
    }
    
    system("pause");
    return 0;
}
