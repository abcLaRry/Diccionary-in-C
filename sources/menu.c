#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "structures.h" // Only for header functions

Letter_t *Letters = NULL;

void clean()
{
    int c;

    puts("Press enter to continue...");
    getchar();
    while ((c = getchar()) != '\n' && c != EOF);
    system("cls||clear");
}

void inicialize()
{
    if(!Letters) {
        Letters = (Letter_t*) calloc(26, sizeof(Letter_t));
        int auxLetters = 97;
        for(int i=0; i<QLETTERS; ++i)
        {
            Letters[i].letter = (char) auxLetters;
            Letters[i].root = NULL;
            Letters[i].quantityWords = 0;

            auxLetters++;
        }
        puts("\nCorrectly initialized, dont forget to free memory at the end");
    }else{
        puts("\nAlready initialized");
    }
}

void addOrDelWord(int f) {
    if(letters) {
        char word[31];
        do{
            fputs("Write the word (30 characters max): ", stdout);
            fgets(word, 30, stdin);
            word[strlen(word)-1] = '\0'; // To delete the '\n' character
        }while(checkInput(word));

        if(f) insertWord(letters, word);
        else freeWord(letters, word);
    }else{
        if(f) puts("The diccionary has not been initialized");
        else puts("The diccionary is empty");
    }
}

void displayAll()
{

}

void showDetails()
{

}

void close()
{

}
