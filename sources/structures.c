#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
        if((check[i]<65||check[i]>122)||(check[i]>90&&check[i]<97)){
            return 0;

        }else if(check[i]>65&&check[i]<90)
            check[i] = check[i]+32;
    }

    if(strlen(check)==0)
        return 0;

    return valid;
}

Node_t* isInTree(Node_t* root, char *word)
{
    if(root==NULL)
        return NULL;

    if(strcmp(word, root->word)<0)
        return isInTree(root->left, word);

    else if(strcmp(word, root->word)>0)
        return isInTree(root->right, word);

    return root;
}

static Node_t* createNode(char *data)
{
    // Memory allocation for a node_t and the new word that it will contain
    Node_t* newNode = malloc(sizeof(Node_t)+sizeof(char)*strlen(data)+1);
    if(!newNode)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->word = (void*) newNode + sizeof(Node_t);
    strcpy(newNode->word, data);
    newNode->right=newNode->left=NULL;

    return newNode;
}

Node_t* insertNode(Node_t* root, char *word)
{
    if(root==NULL)
    {
        root = createNode(word);
        return root;
    }

    if(strcmp(word, root->word)<0 || strcmp(word, root->word)==0) // less than or equal to are inserted in left child
        root->left = insertNode(root->left, word);

    else if(strcmp(word, root->word)>0)
        root->right = insertNode(root->right, word);

    return root;
}

Node_t* deleteNode(Node_t* root, char *word)
{
    if(root==NULL)
        return root;

    if(strcmp(word, root->word)<0)
        root->left = deleteNode(root->left, word);

    else if(strcmp(word, root->word)>0)
        root->right = deleteNode(root->right, word);

    else
    {
        // Node to be deleted found
        if(root->left == NULL)
        {
            Node_t* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            Node_t* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        Node_t* temp = root->right;
        while(temp->left != NULL) {
            temp=temp->left;
        }
        // To avoid memory overflows with the re-allocacion memory
        if(strcmp(root->word, temp->word) < 0)
            free(root->word);

        root = (Node_t*) realloc(root, sizeof(Node_t)+sizeof(char)*strlen(temp->word));
        strcpy(root->word, temp->word);
        root->right = deleteNode(root->right, temp->word);
    }
    return root;
}

void printTree(Node_t* root)
{
    if(root!=NULL)
    {
        printTree(root->left);
        printf("\t%s\n", root->word);
        printTree(root->right);
    }
}

int countNodes(Node_t* root, char* word)
{
    if(root == NULL)
        return 0;

    int count=0;
    if(strcmp(word, root->word) < 0)
        count += countNodes(root->left, word);

    else if(strcmp(word, root->word) > 0)
        count += countNodes(root->right, word);

    else
    {
        // Word to be counted found
        count++;
        count += countNodes(root->left, word);
    }
    return count;
}

void printRepeated(Node_t* root)
{
    if(root!=NULL)
    {
        // The word is only printed if it appears more than once.
        if(countNodes(root, root->word) > 1)
        {
            printf("%s appears %d times\n", root->word, countNodes(root, root->word));
            while(root->left!=NULL)
            {
                // To avoid print more than once a repeated word
                if(strcmp(root->word, root->left->word)==0)
                {
                    // Right childrens are printed before skip this node
                    if(root->right!=NULL)
                        printRepeated(root->right);
                    // Finally the current node is skipped
                    root = root->left;
                }
                else break;
            }
        }
        printRepeated(root->left);
        printRepeated(root->right);
    }
}

void freeAllNodes(Node_t* root)
{
    if(root!=NULL)
    {
        freeAllNodes(root->left);
        freeAllNodes(root->right);
        free(root);
    }
}
