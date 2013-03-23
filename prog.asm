; Primeiro  Exercício-Programa
; Arquivo:  prog.asm  
; 
; Mais informações no arquivo main.c ou em
; git@github.com:renatocf/MAC0323-EP1.git
;
; **** UM PEQUENO PROGRAMA EM HIPO - MAIOR, MENOR E MÉDIA DE ATÉ DEZ INTEIROS ****
;
;
; TESTE DO K
;
00 {INN} 80 ; O programa começa com o usuário informando um número e armazena este número na posição 80, chamarei esse número de "k", e 0<k<=10
01 {LDA} 80 ; O acumulador (Acc) recebe k
02 {JLE} 37 ; Testa se k <= 0, se for, pula para o fim do programa, para parar a execução
03 {SUB} 94 ; Acc -= 10
04 {JGT} 37 ; Testa se k > 10, se for, pula para o fim do programa, para parar a execução
;
; PREAPARAÇÃO DAS VARIAVEIS
;
05 {INN} 81 ; Agora, o programa começa a receber k valores, todos os valores serão armazenado temporariamente na posição 81, chamada de "temp"
06 {LDA} 81 ; O primeiro valor será atribuído às posições de memória nas quais os valores candidatos à menor, maior e média ficarão.
07 {STA} 82 ; A posição 82 será a posição que guardará o valor candidato a ser o menor, chamaremos essa posição de "menor"
08 {STA} 83 ; A posição 83 será a posição que guardará o valor candidato a ser o maior, chamaremos essa posição de "maior"
09 {STA} 84 ; A posição 84 será a posição da soma dos valores de entrada, para calcularmos a média, chamaremos essa posição de "soma"
10 {LDA} 80 ; Precisaremos de um contador para o loop, usaremos o k como referência
11 {STA} 85 ; Colocaremos o número k na posição 85, chamaremos essa posição de "i"
;
; LOOP
;
12 {LDA} 85 ; Aqui começa o loop, Acc = i
13 {SUB} 93 ; acc -= 1
14 {JEQ} 31 ; Aqui é a condição para o break, quando i == 0 ele sai do loop
15 {STA} 85 ; i = acc
16 {INN} 81 ; O usuário entra com um inteiro em temp
17 {LDA} 81 ; acc = temp
18 {SUB} 82 ; acc -= menor, essa subtração serve para a comparação entre menor e temp (que está em acc)
19 {JGE} 22 ; if(temp - menor >= 0) -> pula para 22
20 {LDA} 81 ; else -> acc = temp
21 {STA} 82 ;      -> menor = acc. As linhas 17 à 21 servem para atualizar "menor" caso o último valor informado seja o menor 
22 {LDA} 81 ; acc = temp
23 {SUB} 83 ; acc -= maior, essa subtração serve para a comparação entre maior e temp (que está em acc)
24 {JLE} 27 ; if(temp - maior <= 0) -> pula para 27
25 {LDA} 81 ; else -> acc = temp
26 {STA} 83 ;      -> maior = acc. As linhas 22 à 26 servem para atualizar "maior" caso o último valor informado seja o maior
27 {LDA} 81 ; acc = temp
28 {ADD} 84 ; acc += soma
29 {STA} 84 ; soma = acc. As linhas 27 à 29 podem ser traduzidas como soma += temp
30 {JMP} 12 ; Volta para o início do loop
;
; IMPRESSÃO
;
31 {LDA} 84 ; acc = soma.
32 {DIV} 80 ; acc /= k
33 {STA} 84 ; soma = acc. Antes de imprimir, o programa calcula a média (soma /= k), para isso servem as linhas 31 à 33
34 {PRN} 83 ; Imprime o maior número 
35 {PRN} 82 ; Imprime o menor número
36 {PRN} 84 ; Imprime a média
;
; FIM DO PROGRAMA
;
37 {STP} 00 ;
;
; CONSTANTES
;
93 +0001    ;
94 +0010    ;
