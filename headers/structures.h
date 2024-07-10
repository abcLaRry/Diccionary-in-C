#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

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

/*
    Function headers, only one has parameters that are dependent on the required functionality, details in "trees.c"
*/
void clean();
void inicialize();
void addWord();
void delWord();
void displayAll();
void showDetails();
void close();

#endif // STRUCTURES_H_INCLUDED
