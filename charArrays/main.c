#include <stdio.h>
#include <ctype.h>

char* message = "this is a message";

// simple display - loop throuch message, dereference each char and print it
void display(char* msg){
    while(*msg){
        printf("%c", *msg);
        msg++;
    }
}

void changeToUpper(char* msg){
    while(*msg){
        printf("%c", (char)toupper(*msg));
        msg++;
    }
}

void encrypt(char* msg){
    char c;
    while(*msg){
        c = *msg + 1;
        printf("%c", c);
        msg++;
    }
}

int main(){
    // display(message);
    // changeToUpper(message);
    encrypt(message);
    
    // printf("%s", message); // simpler way to print char*
}
