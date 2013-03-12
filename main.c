#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 5
#define W_SIZE 3
#define G_SIZE 19

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

char **analyse_convert(char **i_matrix);
int check_syntax(char *line, char grammar[G_SIZE][W_SIZE]);
void make_output_line(int i, int result, char **matrix);

int main(int argc, char **argv)
{
    return 0;
}


char **analyse_convert(char **i_matrix)
{
    int i, result;
    char **o_matrix;
    char grammar[G_SIZE][W_SIZE] = 
    {
        "LDA", "STA", "ADD", "SUB", "MUL", "DIV", "REM", "REV", 
        "INN", "PRN", "NOP", "JMP", "JLE", "JDZ", "JGT", "JEQ", 
        "JLT", "JGE", "STP"
    };
    
    /* Dinamically allocate the output matrix */
    /* o_matrix = (char **) malloc(MAX_HEIGHT * sizeof(*o_matrix)); */
    /* for(i = 0; i < MAX_HEIGHT; i++) */
    /* { */
    /*     o_matrix[i] = (char *) malloc(MAX_WIDTH * sizeof(**o_matrix)); */
    /* } */
    
    /* Run the matrix checking for errors */
    for(i = 0; i < MAX_HEIGHT; i++)
    {
        result = check_syntax(i_matrix[i], grammar);
        if(result == -1)
            return NULL;
        else 
            make_output_line(i, result, i_matrix);
    }
}

int check_syntax(char *line, char grammar[G_SIZE][W_SIZE])
{
    int i = 0;
    for(i = 0; i < G_SIZE; i++)
    {
        if(strncmp(line, grammar[i], 3) == 0)
            return i;
    }
    return -1;
}

void make_output_line(int i, int result, char **matrix)
{
    matrix[i][0] = '+';
    switch(i)
    {
        case LDA: /*11*/
            matrix[i][1] = '1'; matrix[i][2] = '1';
            break;
        case STA: /*12*/
            matrix[i][1] = '1'; matrix[i][2] = '2';
            break;
        case ADD: /*21*/
            matrix[i][1] = '2'; matrix[i][2] = '1';
            break;
        case SUB: /*22*/
            matrix[i][1] = '2'; matrix[i][2] = '2';
            break; /
        case MUL: /*23*/
            matrix[i][1] = '2'; matrix[i][2] = '3';
            break;
        case DIV: /*24*/
            matrix[i][1] = '2'; matrix[i][2] = '4';
            break;
        case REM: /*25*/
            matrix[i][1] = '2'; matrix[i][2] = '5';
            break;
        case REV: /*29*/
            matrix[i][1] = '2'; matrix[i][2] = '9';
            break;
        case INN:
            matrix[i][1] = '3'; matrix[i][2] = '1';
            break;
        case PRN:
            matrix[i][1] = '4'; matrix[i][2] = '1';
            break;
        case NOP:
            matrix[i][1] = '5'; matrix[i][2] = '0';
            break;
        case JMP:
            matrix[i][1] = '5'; matrix[i][2] = '1';
            break;
        case JLE:
            matrix[i][1] = '5'; matrix[i][2] = '2';
            break;
        case JDZ:
            matrix[i][1] = '5'; matrix[i][2] = '3';
            break;
        case JGT: 
            matrix[i][1] = '5'; matrix[i][2] = '4';
            break;
        case JEQ:
            matrix[i][1] = '5'; matrix[i][2] = '5';
            break;
        case JLT:
            matrix[i][1] = '5'; matrix[i][2] = '6';
            break;
        case JGE:
            matrix[i][1] = '5'; matrix[i][2] = '7';
            break;
        case STP:
            matrix[i][1] = '7'; matrix[i][2] = '0';
            break;
    }
}
