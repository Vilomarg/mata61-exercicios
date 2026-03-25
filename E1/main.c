#include <stdio.h>
#include "token.h"

extern int yylex();
extern char* yytext;

int main() {
    int token;
    
    // O yylex() vai retornar tokens até encontrar o EOL (que é 0)
    while ((token = yylex()) != EOL) {
        if (token == ERROR) {
            // A proposta diz: "A mensagem de erro deve ser mostrada após o retorno do token ERROR"
            printf("erro léxico: caractere inválido\n");
        } else if (token == NUM) {
            // Saída para números: categoria e o lexema
            printf("categoria do token: %d, constante numérica: %s\n", token, yytext);
        } else {
            // Saída para os operadores (+ - * /)
            printf("categoria do token: %d\n", token);
        }
    }

    return 0;
}
