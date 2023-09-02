#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(void){
     char *line = readline ("# ");
     puts(line);
     free(line);
}
