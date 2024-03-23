#include "ListaGenerica.h"

LISTA_GENERICA *CriarLG()
{
    LISTA_GENERICA *L = (LISTA_GENERICA *)malloc(sizeof(LISTA_GENERICA));
    L->Inicio = NULL;
    L->NEL = 0;
    return L;
}
void AddLG(LISTA_GENERICA *L, void *X)
{
    if (!L) return;
    NOG *aux = (NOG *)malloc(sizeof(NOG));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}
void ShowLG(LISTA_GENERICA *L, void (*f)(void *))
{
    if (!L) return;
    if (!L->Inicio) return;
    NOG *P = L->Inicio;
    while (P)
    {
        f(P->Info);
        P = P->Prox;
    }
}