#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

#define MAX_CONTEUDO 81

typedef struct
{
    int DIA, MES, ANO;
}DATA;

typedef struct
{
    char PNOME[15];
    char LNOME[15];
    char INDENTIFICACAO[15];
    char CARGO[15];
    DATA NASCIMENTO;
    DATA INSCRICAO;
}USER;

USER *CriarUSER();
void MostrarUSER(USER *X);
void DestruirUSER(USER *X);
#endif // USER_H_INCLUDED