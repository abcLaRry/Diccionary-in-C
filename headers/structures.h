#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#define QLETTERS 26 // This definition is the quantity of letters that exist in english alphabet

/*
    Definition of a tree node (it is contained in Letter_t)
*/
typedef struct _nodeT {
    char *word;
    struct _noteT *right, *left;
} Node_t;

/*
    Definition of the data structure for each Letter
*/
typedef struct _node {
    char letter;
    Node_t* root;
    int quantityWords;
} Letter_t;

int checkInput(char *check);
void insertWord(char *word);

#endif // STRUCTURES_H_INCLUDED
