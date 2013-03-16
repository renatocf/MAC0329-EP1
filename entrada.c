#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1

char **entrada(char *argv[]);
char **funcaoRenatooooo(char **M);
void saida(char **M, int fimLinha);

int main(int argc, char* argv[])
{
    entrada(argv);
     return 0;
}

char **entrada(char *argv[])
{
    int ligado, matrizNula = 0;
    char linha[100];
    int linhaControle[100];
    FILE *arq = fopen(argv[1], "r");
    char **M;
    int i,j, k = 0, linhaCont = 0;
    M = malloc(100*sizeof(char*));

    for(i=0;i<100;i++)
        M[i] = malloc(5 * sizeof (char));

    while(fgets(linha, sizeof(linha), arq) != NULL)
    {
        i=0;
        if( linha[i] != ';' && linha[i]!= '\n')
        {

            while(linha[i] == ' ')i++;
            if(linha[i] >='0' && linha[i] <='9' && linha[++i] >= '0' && linha[i] <='9')
            {
                linhaCont = ((linha[--i])-48)*10 + (linha[++i])-48;
                i++;
                while(linha[i] == ' ')i++;
                if(linha[i] == '+' || linha[i]=='-')
                {

                    M[linhaCont][0] = linha[i++];
                    M[linhaCont][1] = linha[i++];
                    M[linhaCont][2] = linha[i++];
                    M[linhaCont][3] = linha[i++];
                    M[linhaCont][4] = linha[i++];
                    linhaControle[k++] = linhaCont;
                }
                else if(linha[i] == '{')
                {
                    i++;
                    while(linha[i]==' ')i++;
                    M[linhaCont][0] = linha[i++];
                    M[linhaCont][1] = linha[i++];
                    M[linhaCont][2] = linha[i++];
                    while(linha[i] == ' ') i++;
                    if(linha[i]=='}')
                    {
                        i++;
                        linhaControle[k++] = linhaCont;
                        while(linha[i]==' ')i++;
                        if(linha[i]>='0' && linha[i]<='9' && linha[++i]>='0' && linha[i] <= '9')
                        {
                            M[linhaCont][3] = linha[--i];
                            M[linhaCont][4] = linha[++i];
                            i++;

                        }
                    }
                    else
                    {
                        funcaoRenatooooo(NULL);
                        matrizNula = 1;
                    }

                }
                else
                {
                    funcaoRenatooooo(NULL);
                    matrizNula = 1;
                }


                while(linha[i] == ' ')i++;
                if(linha[i] != ';' && linha[i]!= '\n')
                {
                    funcaoRenatooooo(NULL);
                    matrizNula = 1;
                }
            }
        }
    }

    for(j=0; j<k-1;j++)
    {
        if(linhaControle[j] > linhaControle[j+1])
        {
            funcaoRenatooooo(NULL);
            matrizNula = 1;
            break;
        }
    }
    if(matrizNula == 0)
    {
        for(j=0; j<100; j++)
        {
            ligado = 0;
            for(i=0; i<k; i++)
            {
                if(j==linhaControle[i])
                    ligado = 1;
            }
            if(!ligado)
            {
                M[j][0] = '\n';
            }
        }
        funcaoRenatooooo(M);
    }



fclose(arq);

return 0;
}

char **funcaoRenatooooo(char **M)
{
    /*crie uma variável q marque  a última linha q tenha algum caracter diferente de \n e mande-a pra a função saída!! xD

    E caso não tenham números, colocar espaço no lugar deles*/
    return M;
}


void saida(char **M, int fimLinha)
{
    int i, j;
    FILE *arq1;
    if((arq1 = fopen("saída.hip", "w"))== NULL)
    {
        printf("Erro ao abrir arquivo!!!\n");
        exit(1);
    }
    else
    {
        for( i = 0; i<100 && i<=fimLinha; i++)
        {
            if(M[i][0]!= '\n')
            {
                for(j = 0; j<5; j++)
                {
                    fputc(M[i][j],arq1);
                }
            }
            fputc('\n', arq1);

        }
        fclose(arq1);
    }

}
