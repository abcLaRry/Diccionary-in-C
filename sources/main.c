#include <stdio.h>
#include "menu.h"

int main() {
    char opc;

    do{
        puts("\tDiccionary in C language\n");
        puts("a. Initialize diccionary");
        puts("b. Add word");
        puts("c. Delete word");
        puts("d. Display all words");
        puts("e. Search for details on a word");
        puts("f. Display all repeated words");
        fputs("g. Exit and free memory\n> ", stdout);
        scanf("%c", &opc);

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
                break;
            case 'e':
                break;
            case 'f':
                break;
        }

        clean();
    }while(opc != 'g');

    return 0;
}
