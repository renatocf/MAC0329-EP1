#include<stdio.h>
#include<stdlib.h>
#define FALSE 0
#define TRUE 1
int main(int argc, char* argv[])
{
    int ligado;
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
                    M[linhaCont][0] = linha[++i];
                    M[linhaCont][1] = linha[++i];
                    M[linhaCont][2] = linha[++i];

                    if(linha[++i]=='}')
                    {
                        linhaControle[k++] = linhaCont;
                        i++;
                        while(linha[i]==' ')i++;
                        if(linha[i]>='0' && linha[i]<='9' && linha[++i]>='0' && linha[i] <= '9')
                        {
                            M[linhaCont][3] = linha[--i];
                            M[linhaCont][4] = linha[++i];
                            i++;

                        }
                    }
                    else
                        printf("CONEEEEEEEEE\n");
                }
                else
                    printf("Errroooooooooo!!!");

                while(linha[i] == ' ')i++;
                if(linha[i] != ';' && linha[i]!= '\n')
                    printf("Errrooooooooooooooooooooooooo!!");

            }

        }

    }

    for(j=0; j<k-1;j++)
    {
        if(linhaControle[j] > linhaControle[j+1])
        {
            printf("CONEEEEEEEEE3\n");
            break;
        }
    }

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

 for(i=0;i<100;i++)
  for(j=0;j<5;j++)
    printf("%c",M[i][j]);

fclose(arq);
 return 0;
}
