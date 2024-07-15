#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED
#define QLETTERS 26 // This definition is the quantity of letters that exist in english alphabet
/*
    Definition of a tree node (it is contained in Letter_t)
*/
typedef struct _nodeT {
    char *word;
    struct _nodeT *right, *left;
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
Node_t* isInTree(Node_t* root, char *word);
Node_t* insertNode(Node_t* root, char *word);
Node_t* deleteNode(Node_t* root, char *word);
void printTree(Node_t* root);
int countNodes(Node_t* root, char* word);
void printRepeated(Node_t* root);
void freeAllNodes(Node_t* root);

#endif // STRUCTURES_H_INCLUDED
