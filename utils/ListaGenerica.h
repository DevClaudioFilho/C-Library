#ifndef LISTAGENERICA_H_INCLUDED
#define LISTAGENERICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct nog
{
    void       *Info;
    struct nog *Prox;
}NOG;

typedef struct
{
    int NEL;
    NOG *Inicio;
}LISTA_GENERICA;

LISTA_GENERICA *CriarLG();
void AddLG(LISTA_GENERICA *L, void *X);
void ShowLG(LISTA_GENERICA *L, void (*f)(void *));

#endif // LISTAGENERICA_H_INCLUDED
