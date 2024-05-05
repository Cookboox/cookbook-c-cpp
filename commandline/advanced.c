#include <stdio.h>

// take multiple command line args and print them to file
// gcc advanced.c -o adv && adv hello.scv hello world.csv world
// tohle mi rika ze argv[0] je adv, argv[1] je hello.csv, argv[2] je hello, argv[3] je world.csv, argv[4] je world.
 // po spusteni timhel commandem: gcc advanced.c -o adv && adv hello.scv hello world.csv world to vytvori dva soubory  a napise to tam ty slova

int main(int argc, char* argv[]){

    FILE* firstFile = fopen(argv[1], "w"); // hello.csv
    FILE* secondFile = fopen(argv[3], "w"); // world.csv

    
    fprintf(firstFile, "%s", argv[2]);
    fclose(firstFile);

    fprintf(secondFile, "%s", argv[4]);
    fclose(secondFile);
}
