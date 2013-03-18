/* Tamanho da matriz de entrada/saída */
enum matrix { MAX_HEIGHT=100, MAX_WIDTH=5 };

char **analyse_convert(char **i_matrix);
/* Recebe uma matriz com comandos mneumônicos do HIPO e a devolve
 * com a tradução para código de máquina. Devolve 'NULL' se houver
 * erro de sintaxe */
