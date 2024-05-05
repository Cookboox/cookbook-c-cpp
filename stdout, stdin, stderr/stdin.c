#include <stdio.h>

int main(){
    char name[10];

    puts("your name?");
    scanf("%s", name); 
    // fscanf(stdin, "%s", name); //same as above, but as it specifies stream, it can be redirected to std err for example

    printf("your name is %s", name);    
}


// 1] compile with gcc stdin.c -o stdin
// 2] run with gcc stdin < fromfile (and it will read the name from file)
