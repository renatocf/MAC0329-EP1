#include<stdio.h>
#include<stdlib.h>

/* Libraries */
#include "analyzer.h"

int main(int argc, char **argv)
{
    char **teste; int i; /* char *ch; char a = 'a'; */
    teste = (char **) malloc(MAX_HEIGHT * sizeof(char *));
    for(i = 0; i < MAX_HEIGHT; i++)
    {
        teste[i] = (char *) malloc(MAX_WIDTH * sizeof(char));
    }
    
    teste[0] = "INN20";
    teste[1] = "ADD20";
    teste[2] = "+2020";
    teste[3] = "\n";
    teste[4] = "-2020";
    
    analyse_convert(teste);
    
    printf("After conversion:\n");
    for(i = 0; i < MAX_HEIGHT-80; i++)
        printf("%2.d %s\n", i, teste[i]);
    
    return 0;
}
