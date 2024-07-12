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

void insertWord(Letter_t* diccionary, char *word)
{
    int letterPos = 0;
    for(letterPos=0; letterPos<QLETTERS; ++letterPos)
        if((char) letterPos+97 == word[0]) break;

    // Memory allocation for a node_t and the new word that it will contain
    Node_t* newNode = malloc(sizeof(Node_t)+sizeof(char)*strlen(word)+1);
    newNode->word = (void*) newNode + sizeof(Node_t);
    strcpy(newNode->word, word);
    newNode->right=newNode->left=NULL;

    // Case 1: Root does not exist
    if(!diccionary[letterPos].root)
        diccionary[letterPos].root = newNode;

    // Case 2: Root exist
    else {
        Node_t* reco = diccionary[letterPos].root;
        Node_t* pre = NULL;
        while(reco!=NULL)
        {
            pre = reco;
            if(strcmp(newNode->word, reco->word)<0)
                reco=reco->left;
            else
                reco=reco->right;
        }
        if(strcmp(newNode->word, pre->word)<0)
            pre->left = newNode;
        else
            pre->right = newNode;
    }
}

void freeWord(Letter_t* diccionary, char *word)
{

}

