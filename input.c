/***************************************************/
/**  Primeiro  Exercício-Programa                 **/
/**  Arquivo:  analyzer.c                         **/
/**                                               **/
/**  Mais informações no arquivo main.c ou em     **/
/**  git@github.com:renatocf/MAC0323-EP1.git      **/
/***************************************************/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Bibliotecas */
#include "input.h"

/* Macros */
#define FALSE 0
#define TRUE 1

/* Recebe o nome de um arquivo de texto e, caso o arquivo esteja de
 * acordo com a sintaxe HIPO, devolve uma matriz com os caracteres
 * necessarios para o programa.*/
char **entrada(char *nome)
{
    int  ligado;
    int i = 0, j = 0, k = 0, linhaCont = 0;
    /* Armazena a string da linha a ser lida */
    char linha[80];
    int  linhaControle[100];
    char **M;

    /* Abrindo arquivo passado pelo usuário*/
    FILE *arq = fopen(nome, "r");

    /*Criação da matriz que sera retornada*/
    M = malloc(100*sizeof(char*));
    for(i=0;i<100;i++)
        M[i] = malloc(5 * sizeof (char));

    /* Percorre todo o arquivo até que o mesmo acabe ou seja
     * encontrado um erro de sintaxe. Espaços brancos são ignorados
     * desde que nao estejam entre numeros (0 9) ou entre instruções
     * (I NN)*/
    while(fgets(linha, sizeof(linha), arq) != NULL)
    {
        i=0;

        /* Vai pra proxima linha do arquivo caso
         * linha[i] == ';' ou linha[i] == '\n'*/
        if(linha[i] != ';' && linha[i]!= '\n')
        {
            /*Ignorando espaços em branco*/
            while(linha[i] == ' ' || linha[i] == '\t') i++;

            if(linha[i] >='0' && linha[i] <='9'
            && linha[++i] >= '0' && linha[i] <='9')
            {
                /* Transforma os caracteres do endereço encontrado em
                 * inteiro e o guarda em linhaCont, para se saber em
                 * qual linha da matriz a instrução deve ser escrita */
                linhaCont = (linha[i-1]-48)*10 + (linha[i]-48);
                i++;

                /*Ignorando espaços em branco*/
                while(linha[i] == ' ' || linha[i] == '\t') i++;

                if(linha[i] == '+' || linha[i]=='-')
                {
                    for(j = i+1; j < 5; j++)
                        if(linha[j] > '9' || linha[j] < '0') return NULL;

                    /* Adiciona os 5 próximos caracteres
                     * depois do sinal na matriz */
                    M[linhaCont][0] = linha[i++];
                    M[linhaCont][1] = linha[i++];
                    M[linhaCont][2] = linha[i++];
                    M[linhaCont][3] = linha[i++];
                    M[linhaCont][4] = linha[i++];

                    /*Guarda quais linhas da matriz estarão preenchidas*/
                    linhaControle[k++] = linhaCont;
                }
                else if(linha[i] == '{')
                {
                    i++;

                    /*Ignora os espaços em branco*/
                    while(linha[i]==' ' || linha[i] == '\t') i++;

                    /*Adiciona os proximos 3 caracteres para a matriz*/
                    M[linhaCont][0] = linha[i++];
                    M[linhaCont][1] = linha[i++];
                    M[linhaCont][2] = linha[i++];

                    /*Ignora espaços em branco*/
                    while(linha[i] == ' ' || linha[i] == '\t') i++;

                    if(linha[i]=='}')
                    {
                        i++;
                        linhaControle[k++] = linhaCont;

                        /*Ignora espaços em branco*/
                        while(linha[i]==' ' || linha[i] == '\t') i++;

                        if(linha[i]>='0' && linha[i]<='9'
                        && linha[++i]>='0' && linha[i]<='9')
                        {
                            /* Adiciona os próximos dois
                             * caracteres para a matriz*/
                            M[linhaCont][3] = linha[--i];
                            M[linhaCont][4] = linha[++i];
                            i++;
                        }
                    }
                    /*Caso ocorra erro de sintaxe*/
                    else
                        return NULL;
                }
                /*Caso ocorra erro de sintaxe*/
                else return NULL;

                /*Ignora espaços*/
                while(linha[i] == ' ' || linha[i] == '\t') i++;

                /* Procura por caracteres diferentes de ';' e '\n'.
                 * Se achar, significa que ocorreu erro de sintaxe */
                if(linha[i] != ';' && linha[i]!= '\n') return NULL;
            }
        }
    }

    /* Verifica se o vetor linhaControle está ordenado.
     * Caso não esteja, ocorreu um erro de sintaxe */
    for(j=0; j<k-1;j++)
        if(linhaControle[j] >= linhaControle[j+1])
            return NULL;

    /* Percorre a matriz colocando '\n' na primeira coluna
     * das linhas que não estao em linhaControle */
    for(j=0; j<100; j++)
    {
        ligado = 0;
        for(i=0; i<k; i++)
        {
            if(j==linhaControle[i])
                ligado = 1;
            /* Caso a matriz tenha uma linha em comum com
             * a linha do programa, ligado receberá valor 1,
             * ou seja... se ligado passar a ser 1, não será
             * necessário imprimir \n na primeira coluna da
             * matriz */
        }
        if(!ligado)
            M[j][0] = '\n';
    }

    /* Se chegou até aqui, significa que a entrada esta sintatica-
     * mente correta. Instruções erradas serão verificadas pela
     * próxima função*/

    /*Fechando arquivo*/
    fclose(arq);
    return M;
}

void saida(char **M, int fimLinha, char *nome)
{
    int i, j;
    FILE *arq1;
    char *saida;

    printf("fimLinha: %d", fimLinha);
    /* Cria nome da função de saida */
    for(i = strlen(nome)-1; i > 0; i--)
        if(nome[i] == '.') break;

    /* Se i for 0, não encontrou '.' */
    if(i == 0) i = strlen(nome)-1;

    saida = malloc(i * sizeof(*saida));
    saida = strncpy(saida, nome, i);
    saida = strcat(saida, ".hip");

    /* Abre arquivo para ser copiado */
    if((arq1 = fopen(saida, "w")) == NULL)
    {
        printf("Erro ao abrir arquivo!!!\n");
        exit(1);
    }
    else /*Caso não dê erros na criação desse arquivo...*/
    {
        for( i = 0; i<=fimLinha && i<=100 ; i++)
            /*Percorrer todas as linhas da matriz*/
        {
            if(M[i][0] != '\n')
                /*enquanto houver algum caracter na matriz*/
            {
                for(j = 0; j<5; j++)
                {
                    /* Caso haja o caracter em determinada linha da
                     * matriz, imprime a linha no arquivo de saida */
                    fputc(M[i][j],arq1);
                }
            }
            fputc('\n', arq1);
            /* Pula a linha de acordo com a mudança de linha
             * na matriz percorrida*/
        }

        fclose(arq1);
        /*Fecha arquivo de saida */

    } /*else*/

    free(saida); saida = NULL; arq1 = NULL;

} /*saida*/
