#include <stdio.h>
#include "menu.h"

int main() {
    int c;
    char opc;

    do{
        puts("\tDictionary in C language\n");
        puts("a. Initialize dictionary");
        puts("b. Add word");
        puts("c. Delete word");
        puts("d. Display all words");
        puts("e. Search for details on a word");
        puts("f. Display all repeated words");
        fputs("g. Exit and free memory\n> ", stdout);
        scanf("%c", &opc);
        while ((c = getchar()) != '\n' && c != EOF);

        switch(opc) {
            case 'a':
                inicialize();
                break;
            case 'b':
                addOrDelWord(1);
                break;
            case 'c':
                addOrDelWord(0);
                break;
            case 'd':
                displayAll();
                break;
            case 'e':
                showDetails();
                break;
            case 'f':
                displayRepeated();
                break;
            case 'g':
                close();
                opc = '\t';
                break;
        }

        clean();
    }while(opc != '\t');

    return 0;
}
