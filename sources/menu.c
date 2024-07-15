#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "structures.h"

Letter_t diccionary[QLETTERS] = {};
int ini = 0; // For validation

void clean()
{
    int c;

    puts("Press enter to continue...");
    while ((c = getchar()) != '\n' && c != EOF);
    system("cls||clear");
}

void inicialize()
{
    if(!ini) {
        int auxLetters = 97;
        for(int i=0; i<QLETTERS; ++i)
        {
            diccionary[i].letter = (char) auxLetters;
            diccionary[i].root = NULL;
            diccionary[i].quantityWords = 0;

            auxLetters++;
        }
        ini = 1;
        puts("\nCorrectly initialized, dont forget to free memory at the end");
    }else
        puts("\nAlready initialized");
}

void addOrDelWord(int f) {
    if(ini) {
        char word[31];
        do{
            fputs("Type the word (30 characters max): ", stdout);
            fgets(word, 30, stdin);
            word[strlen(word)-1] = '\0'; // To delete the '\n' character
        }while(!checkInput(word));

        int letterPos = 0;
        for(letterPos=0; letterPos<QLETTERS; ++letterPos)
            if((char) letterPos+97 == word[0]) break;

        if(f)
        {
            diccionary[letterPos].root = insertNode(diccionary[letterPos].root, word);
            diccionary[letterPos].quantityWords++;
            puts("Added succesfully.");
        }
        else
        {
            if(isInTree(diccionary[letterPos].root, word))
            {
                diccionary[letterPos].root = deleteNode(diccionary[letterPos].root, word);
                diccionary[letterPos].quantityWords--;
                puts("Deleted successfully.");
            }
            else
                puts("Word not found.");
        }
    }else{
        if(f) puts("The diccionary has not been initialized");
        else puts("The diccionary is empty");
    }
}

void displayAll()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
        {
            if(diccionary[i].root!=NULL)
            {
                printf("Letter %c has %d word(s):\n", i+97, diccionary[i].quantityWords);
                printTree(diccionary[i].root);
            }
        }
    }else
        puts("The diccionary is empty");
}

void showDetails()
{
    if(ini) {
        char word[31];
        do{
            fputs("Type the word for which you want to know its information: ", stdout);
            fgets(word, 30, stdin);
            word[strlen(word)-1] = '\0'; // To delete the '\n' character
        }while(!checkInput(word));

        int letterPos = 0;
        for(letterPos=0; letterPos<QLETTERS; ++letterPos)
            if((char) letterPos+97 == word[0]) break;

        int count = countNodes(diccionary[letterPos].root, word);
        printf("The word \"%s\"\n", word);
        printf("Appears %d time(s) in diccionary\n", count);
    }else
        puts("The diccionary is empty");
}

void displayRepeated()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
            printRepeated(diccionary[i].root);
    }else
        puts("The diccionary is empty");
}

void close()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
            freeAllNodes(diccionary[i].root);
    }else
        puts("The diccionary is empty");
}
