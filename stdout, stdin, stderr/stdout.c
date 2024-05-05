  
#include <stdio.h>

int main(){
    printf("i am stdout \n");
    fprintf(stdout, "i am stdout"); // identical
}

// you can redirect stdout to a file using > in command line
// 1] compile the code with gcc stdout.c -o stdout
// 2] run the .exe file with stdout > tofile.txt (it will create the file and writes it there)
// alternativelly you can do it in one go with: gcc stdout.c -o stdout && stdout > tofile.txt
