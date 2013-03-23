/***************************************************/
/**  Primeiro  Exercício-Programa                 **/
/**  Arquivo:  HIPO.h                             **/
/**                                               **/
/**  Mais informações no arquivo main.c ou em     **/
/**  git@github.com:renatocf/MAC0323-EP1.git      **/
/***************************************************/ 

#ifndef H_HIPO_DEFINED
#define H_HIPO_DEFINED

/* Tamanho para a tabela de comandos do HIPO */
enum commands{ L_SIZE=19, W_SIZE=4 };

/* Comandos reconhecidos pelo HIPO */
static const char grammar[L_SIZE][W_SIZE] = 
{
    "LDA", "STA", "ADD", "SUB", "MUL", "DIV", "REM", "REV", 
    "INN", "PRN", "NOP", "JMP", "JLE", "JDZ", "JGT", "JEQ", 
    "JLT", "JGE", "STP"
};

#endif
