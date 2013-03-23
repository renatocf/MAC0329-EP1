/***************************************************/
/**  Primeiro  Exercício-Programa                 **/
/**  Arquivo:  analyzer.h                         **/
/**                                               **/
/**  Mais informações no arquivo main.c ou em     **/
/**  git@github.com:renatocf/MAC0323-EP1.git      **/
/***************************************************/ 

#ifndef H_ANALYZER_DEFINED
#define H_ANALYZER_DEFINED

/* Tamanho da matriz de entrada/saída */
enum matrix { MAX_HEIGHT=100, MAX_WIDTH=5 };

char **analyse_convert(char **i_matrix);
/* Recebe uma matriz com comandos mneumônicos do HIPO e a devolve
 * com a tradução para código de máquina. Devolve 'NULL' se houver
 * erro de sintaxe */

extern int last_line;

#endif
