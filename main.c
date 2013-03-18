#include<stdio.h>
#include<stdlib.h>

/* Libraries */
#include "input.h"
#include "analyzer.h"

char error_message[] = "Erro de sintaxe\n";

int main(int argc, char **argv)
{
    char **matrix;
    /* char **teste; int i; #<{(| char *ch; char a = 'a'; |)}># */
    /* teste = (char **) malloc(MAX_HEIGHT * sizeof(char *)); */
    /* for(i = 0; i < MAX_HEIGHT; i++) */
    /* { */
    /*     teste[i] = (char *) malloc(MAX_WIDTH * sizeof(char)); */
    /* } */
    /*  */
    /* teste[0] = "INN20"; */
    /* teste[1] = "ADD20"; */
    /* teste[2] = "+2020"; */
    /* teste[3] = "-2020"; */
    /* teste[4] = "STP  "; */
    
    
    if((matrix = entrada(argv)) == NULL)
    {
        printf("\n%s\n", error_message);
        return EXIT_FAILURE;
    }
    
    if((matrix = analyse_convert(matrix)) == NULL)
    {
        printf("\n%s\n", error_message);
        return EXIT_FAILURE;
    }
    
    saida(matrix, last_line, argv[1]);

    /* printf("After conversion:\n"); */
    /* for(i = 0; i < MAX_HEIGHT-80; i++) */
    /*     printf("%2.d %s\n", i, teste[i]); */
    
    return EXIT_SUCCESS;
}
