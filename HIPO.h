/* Tamanho para a tabela de comandos do HIPO */
enum commands{ L_SIZE=19, W_SIZE=4 };

/* Comandos reconhecidos pelo HIPO */
static const char grammar[L_SIZE][W_SIZE] = 
{
    "LDA", "STA", "ADD", "SUB", "MUL", "DIV", "REM", "REV", 
    "INN", "PRN", "NOP", "JMP", "JLE", "JDZ", "JGT", "JEQ", 
    "JLT", "JGE", "STP"
};
