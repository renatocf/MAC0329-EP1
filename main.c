/***************************************************/
/**  MAC 0329  -  Álgebra Boobleana e Aplicações  **/
/**  IME-USP   -  Primeiro  Semestre  de    2013  **/
/**  Turma 45  -  Junior Barrera                  **/
/**                                               **/
/**  Primeiro  Exercício-Programa                 **/
/**  Arquivo:  main.c                             **/
/**                                               **/
/**  Karina Suemi Awoki                  7572102  **/
/**  Renato Cordeiro Ferreira            7990933  **/
/**  Ruan de Menezes Costa               7990929  **/
/**  Vinicius Nascimento Silva           7557626  **/
/**                                               **/
/**  Em caso de eventuais problemas, acesse:      **/
/**  git@github.com:renatocf/MAC0323-EP1.git      **/
/***************************************************/ 

#include<stdio.h>
#include<stdlib.h>

/* BIbliotecas */
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
