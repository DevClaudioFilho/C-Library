#include "user.h"

extern int Aleatorio(int min, int max);
//------------------------------------
int CONT = 10;
USER *CriarUSER()
{
    USER *X = (USER *)malloc(sizeof(USER));
    DATA *D = (DATA *)malloc(sizeof(DATA));
    sprintf(X->PNOME, "Primeiro Nome: %s", CONT);
    sprintf(X->LNOME, "Ultimo Nome--> %d", CONT);
    // Ver como pegar multiplos valores em uma linha
    sprintf(D->NASCIMENTO, "Nascimento(dd/mm/aaaa)--> %d/%d/%d", CONT);
    sprintf(X->INDENTIFICACAO, "Zezito--> %d", CONT);
    sprintf(X->CARGO, "Zezito--> %d", CONT);
    CONT ++;
    return X;
}
void MostrarUSER(USER *X)
{
    printf("\nUSER:\n");
    printf("\t CLIENTE: [%s]", X->PNOME);
}
void DestruirUSER(USER *X)
{
    if (X) free (X);
}
