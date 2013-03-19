/*
///////////////////////////////////////////////////////////////////////
----------------------------------------------------------------------
                         MACROS E BIBLIOTECAS     
----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "HIPO.h"
#include "analyzer.h"

#define POS_NUMBER '+'
#define NEG_NUMBER '-'
#define BLANK_LINE -1
#define SYNTAX_ERROR -2

/*
///////////////////////////////////////////////////////////////////////
----------------------------------------------------------------------
                               PROTÓTIPOS         
----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/

/* Comandos do HIPO */
typedef enum {
    LDA=0, STA=1, ADD=2, SUB=3, MUL=4, DIV=5, REM=6, REV=7, INN=8, 
    PRN=9, NOP=10, JMP=11, JLE=12, JDZ=13, JGT=14, JEQ=15, JLT=16, 
    JGE=17, STP=18 
} HIPO;

/* Protótipos de funções de uso interno */
static int 
check_syntax(char *line, const char grammar[L_SIZE][W_SIZE]);
static char * 
make_output_line(int line, int command, char **matrix);

int last_line;

/*
///////////////////////////////////////////////////////////////////////
----------------------------------------------------------------------
                         FUNÇÕES DE USO PÚBLICO 
----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
char **analyse_convert(char **i_matrix)
    /* Recebe uma matriz com comandos mneumônicos do HIPO e a devolve
     * com a tradução para código de máquina. Devolve 'NULL' se houver
     * erro de sintaxe */
{
    int i, result;
    
    for(i = 0; i < MAX_HEIGHT; i++)
    {
        result = check_syntax(i_matrix[i], grammar);
        switch(result)
        {
            case SYNTAX_ERROR:
                return NULL;
                break;
            case BLANK_LINE:
                break;
            default:
                last_line = i;
                i_matrix[i] = make_output_line(i, result, i_matrix);
        }
        /* printf("linha i=%d ", i); */
        /* printf("%c", i_matrix[i][0]); */
        /* printf("%c", i_matrix[i][1]); */
        /* printf("%c", i_matrix[i][2]); */
        /* printf("%c", i_matrix[i][3]); */
        /* printf("%c\n", i_matrix[i][4]); */
    }
    return i_matrix;
}

/*
///////////////////////////////////////////////////////////////////////
----------------------------------------------------------------------
                         FUNÇÕES DE USO PRIVADO 
----------------------------------------------------------------------
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
*/
static int check_syntax(char *line, const char grammar[L_SIZE][W_SIZE])
    /* Recebe uma sring de texto e uma lista de palavras. Devolve:
     * -> POS_NUMBER se o primeiro caracter for '+';
     * -> NEG_NUMBER se o 1º caracter for '-'; 
     * -> BLANK_LINE para 1º caracter '\n'. 
     * -> Um inteiro representado a palavra encontrada na lista;
     * -> SYNTAX_ERROR, caso nenhuma das condições anteriores
     *    valha. */
{
    int i = 0;
    switch(line[0])
    {
        case '+':
            return POS_NUMBER;
        case '-':
            return NEG_NUMBER;
        case '\n':
            return BLANK_LINE;
        default:
            for(i = 0; i < L_SIZE; i++)
                if(strncmp(line, grammar[i], 3) == 0) return i;
    }
    return SYNTAX_ERROR;
}

static char *make_output_line(int line, int command, char **matrix)
    /* Cria a partir de 'line' da matriz 'matrix' o correspondente
     * código de máquina do HIPO, conforme 'command' previamente 
     * identificado. */ 
{
    char *out = (char *) malloc (W_SIZE * sizeof(*out));
    out[0] = '+'; 
    out[3] = matrix[line][3]; 
    out[4] = matrix[line][4]; 
    
    switch(command)
    {
        case LDA: /*11*/
            out[1] = '1'; out[2] = '1';
            break;
        case STA: /*12*/
            out[1] = '1'; out[2] = '2';
            break;
        case ADD: /*21*/
            out[1] = '2'; out[2] = '1';
            break;
        case SUB: /*22*/
            out[1] = '2'; out[2] = '2';
            break; 
        case MUL: /*23*/
            out[1] = '2'; out[2] = '3';
            break;
        case DIV: /*24*/
            out[1] = '2'; out[2] = '4';
            break;
        case REM: /*25*/
            out[1] = '2'; out[2] = '5';
            break;
        case REV: /*29*/
            out[1] = '2'; out[2] = '9';
            break;
        case INN: /*31*/
            out[1] = '3'; out[2] = '1';
            break;
        case PRN: /*41*/
            out[1] = '4'; out[2] = '1';
            break;
        case NOP: /*50*/
            out[1] = '5'; out[2] = '0';
            out[3] = ' '; out[4] = ' ';
            break;
        case JMP: /*51*/
            out[1] = '5'; out[2] = '1';
            break;
        case JLE: /*52*/
            out[1] = '5'; out[2] = '2';
            break;
        case JDZ: /*53*/
            out[1] = '5'; out[2] = '3';
            break;
        case JGT: /*54*/
            out[1] = '5'; out[2] = '4';
            break;
        case JEQ: /*55*/
            out[1] = '5'; out[2] = '5';
            break;
        case JLT: /*56*/
            out[1] = '5'; out[2] = '6';
            break;
        case JGE: /*57*/
            out[1] = '5'; out[2] = '7';
            break;
        case STP: /*70*/
            out[1] = '7'; out[2] = '0';
            out[3] = ' '; out[4] = ' ';
            break;
        case NEG_NUMBER:
            out[0] = '-'; 
        case POS_NUMBER:
            out[1] = matrix[line][1]; 
            out[2] = matrix[line][2]; 
    }
    return out;
}
