#include <string.h>
#include "structures.h"

/*
    Convert uppercase letters to lowercase, and returns 0 if him find an error
*/
int checkInput(char *check)
{
    int valid = 1;
    // 65 - 90 uppercase, 97 - 122 lowercase
    for(int i=0; i<strlen(check); ++i)
    {
        if(check[i]<65||check>122||(check[i]>90&&check[i]<97)){
            valid = 0;
            break;
        }else
            check[i] = check[i]+32;
    }

    return valid;
}

void insertWord(char *word)
{

}

