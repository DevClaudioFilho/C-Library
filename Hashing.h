#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

typedef struct no_chave
{
    void *KEY;
    LISTA *DADOS;
    struct no_chave *Prox;
}NO_CHAVE;

typedef struct
{
    int NEL;
    NO_CHAVE *Inicio;
}LISTA_CHAVES;

typedef struct
{
    LISTA_CHAVES *LChaves;
}HASHING;

HASHING *CriarHashing();
void DestruirHashing(HASHING *H);
void AddHashing(HASHING *H, void *P,void *NChave, char *type);
NO_CHAVE *FuncaoHashing(HASHING *H, void *X, void *NChave,char *type);
void ShowHashing(HASHING *H,void (*f)(void *),char *type);
void OrdenarHashing(HASHING *H);

#endif // HASHING_H_INCLUDED
