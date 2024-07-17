#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "structures.h"

Letter_t dictionary[QLETTERS] = {};
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
            dictionary[i].letter = (char) auxLetters;
            dictionary[i].root = NULL;
            dictionary[i].quantityWords = 0;

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
            dictionary[letterPos].root = insertNode(dictionary[letterPos].root, word);
            dictionary[letterPos].quantityWords++;
            puts("Added succesfully.");
        }
        else
        {
            if(isInTree(dictionary[letterPos].root, word))
            {
                dictionary[letterPos].root = deleteNode(dictionary[letterPos].root, word);
                dictionary[letterPos].quantityWords--;
                puts("Deleted successfully.");
            }
            else
                puts("Word not found.");
        }
    }else{
        if(f) puts("The dictionary has not been initialized");
        else puts("The dictionary is empty");
    }
}

void displayAll()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
        {
            if(dictionary[i].root!=NULL)
            {
                printf("Letter %c has %d word(s):\n", i+97, dictionary[i].quantityWords);
                printTree(dictionary[i].root);
            }
        }
    }else
        puts("The dictionary is empty");
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

        int count = countNodes(dictionary[letterPos].root, word);
        printf("The word \"%s\"\n", word);
        printf("Appears %d time(s) in dictionary\n", count);
    }else
        puts("The dictionary is empty");
}

void displayRepeated()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
            printRepeated(dictionary[i].root);
    }else
        puts("The dictionary is empty");
}

void close()
{
    if(ini) {
        for(int i=0; i<QLETTERS; ++i)
            freeAllNodes(dictionary[i].root);
    }else
        puts("The dictionary is empty");
}
