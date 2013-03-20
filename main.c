#include<stdio.h>
#include<stdlib.h>

/* Libraries */
#include "input.h"
#include "analyzer.h"

char usage_message[] = "Uso: hipo_assembler arquivo.asm\n";
char error_message[] = "Erro de sintaxe\n";

int main(int argc, char **argv)
{
    char **matrix; /* Matriz auxiliar */
    
    /* Verifica se um argumento foi passado na
     * linha de comando */
    if(argc != 2) 
    {
        printf("\n%s\n", usage_message);
        return EXIT_FAILURE;
    }
    
    /* Recebe entrada a partir do nome do arquivo */
    if((matrix = entrada(argv[1])) == NULL)
    {
        printf("\n%s\n", error_message);
        return EXIT_FAILURE;
    }
    
    /* Converte mneumônicos do HIPO em código de 
     * máquina a partir da sintaxe correta */
    if((matrix = analyse_convert(matrix)) == NULL)
    {
        printf("\n%s\n", error_message);
        return EXIT_FAILURE;
    }
    
    /* Cria o arquivo de saída (extensão .hip) */
    saida(matrix, last_line, argv[1]);
    
    return EXIT_SUCCESS;
}
