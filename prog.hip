INN50 +3150 ; Recebe 'k' para a posição 50
LDA50 +1150 ; Coloca 'k' no acumulador
JLE70 +5270 ; Compara acumulador com <= 0. Se verdade, interrompe
SUB62 +2262 ; Subtrai acumulador de 10
JGT70 +5470 ; Se a resposta for > 0, para.
LDA50 +1150 ; Coloca 'k' no acumulador
INN51 +3151 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN52 +3152 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN53 +3153 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN54 +3154 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN55 +3155 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN56 +3156 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN57 +3157 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN58 +3158 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN59 +3159 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
JEQ37 +5537 ; 
INN60 +3160 ; Coloca primeiro número na posição 51
SUB62 +2262 ; Decrementa o 'k' do acumulador
LDA51 +1151 ; Coloca o primeiro número no ACC
ADD52 +2152 ; Soma a posição 52
ADD53 +2153 ; Soma a posição 53
ADD54 +2154 ; Soma a posição 54
ADD55 +2155 ; Soma a posição 55
ADD56 +2156 ; Soma a posição 56
ADD57 +2157 ; Soma a posição 57
ADD58 +2158 ; Soma a posição 58
ADD59 +2159 ; Soma a posição 59
ADD60 +2160 ; Soma a posição 60
DIV50 +2450 ; Divide a soma por 'k'
STA54 +1254 ; Coloca a soma na posição 54

-- memória
            ; Valor 'k'
+0000 +0000 ; 1ª entrada
+0000 +0000 ; 2ª entrada 
+0000 +0000 ; 3ª entrada
+0000 +0000 ; 4ª entrada
+0000 +0000 ; 5ª entrada
+0000 +0000 ; 6ª entrada
+0000 +0000 ; 7ª entrada
+0000 +0000 ; 8ª entrada
+0000 +0000 ; 9ª entrada
+0000 +0000 ; 10ª entrada
--
+0010 +0010
+0001 +0001







STP70 +7070
