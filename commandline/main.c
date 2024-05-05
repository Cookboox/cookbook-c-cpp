#include <stdio.h>

int main(int argc, int* argv[]){

    printf("first param is: %s ", argv[1]);
    printf("second param is: %s ", argv[2]);

}

//  run: gcc main.c -o main && main HELLO WORLD 
//  first param is: HELLO second param is: WORLD 
