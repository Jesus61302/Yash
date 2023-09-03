#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <readline/history.h>


void tokenize(char* line, char** arr){
    char* token;
    char* token_ptr;
    token = strtok_r(line, " ", &token_ptr);
    int i = 0;
    while (token != NULL){
        arr[i] = token;
        token = strtok_r(NULL, " ", &token_ptr);
        i++;
    }
}

int main(void){
    char* tokens[50] = {"temp"}; 
    char* line;
    int cpid;
    while(line = readline("# ")){
        tokenize(line, tokens);
        cpid = fork();
        if (cpid == 0){
            execvp(tokens[0], tokens);
        }else{
            wait((int *)NULL);
        }
        free(line);
    }
    
    // char *arr[50] = {"C"};
    // // char **ptr = arr;
    // arr[2] = "Sander";
    // arr[1] = "Hello";
    // arr[0] = "my";
    // int i = 0;
    // while(arr[i] != NULL){
    //     // printf("String %d : %s\n", i+1, ptr[i] );
    //     puts(arr[i]);
    //     i++;
    // }
    // return 0;            
}

