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

void AddLista(LISTA *L, void *X,char *log_file);
void ShowLista(LISTA *L, void (*f)(void *),char *log_file);
void *PesquisarLista(LISTA *L, int (*fcomp)(void *, void *,void *), void *palavra,char *log_file);
void RemoverLista(LISTA *L, void *VInfo,char *log_file);
void DestruirLista(LISTA *L,char *log_file);
int SizeLista(LISTA *L,char *log_file);

#endif // LISTA_H_INCLUDED

