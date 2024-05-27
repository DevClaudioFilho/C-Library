#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    void    *Info;
    struct no *Prox;
}NO;

typedef struct
{
    int NEL;
    NO *Inicio;
}LISTA;

LISTA *CriarLista();

void AddLista(LISTA *L, void *X);
void ShowLista(LISTA *L, void (*f)(void *));
void *PesquisarLista(LISTA *L, int (*fcomp)(void *, void *), void *palavra);
void RemoverLista(LISTA *L, void *VInfo);
void DestruirLista(LISTA *L);
int SizeLista(LISTA *L);

#endif // LISTA_H_INCLUDED

