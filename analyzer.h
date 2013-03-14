#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Tamanho para a matriz de entrada/saída */
#define MAX_HEIGHT 100
#define MAX_WIDTH 5

/* Tamanho para a tabela de comandos */
#define W_SIZE 4
#define G_SIZE 19

/* Comandos do HIPO */
#define LDA 0
#define STA 1
#define ADD 2
#define SUB 3 
#define MUL 4
#define DIV 5
#define REM 6
#define REV 7
#define INN 8
#define PRN 9
#define NOP 10
#define JMP 11
#define JLE 12
#define JDZ 13
#define JGT 14 
#define JEQ 15
#define JLT 16
#define JGE 17
#define STP 18

/* Constantes, linha em branco e erros */
#define POS_NUMBER '+'
#define NEG_NUMBER '-'
#define BLANK_LINE -1
#define SYNTAX_ERROR -2

char **analyse_convert(char **i_matrix);
int check_syntax(char *line, char grammar[G_SIZE][W_SIZE]);
char * make_output_line(int line, int command, char **matrix);
