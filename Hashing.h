#ifndef HASHING_H_INCLUDED
#define HASHING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

LISTA_CHAVES *CriarListaCHAVES();
NO_CHAVE *AddCHAVE(LISTA_CHAVES *L, void *key, char *type);
HASHING *CriarHashing();
void DestruirHashing(HASHING *H,char *log_file);
void AddHashing(HASHING *H, void *P,void *NChave, char *type,char *log_file);
NO_CHAVE *FuncaoHashing(HASHING *H, void *X,void *NChave,char *type,char *log_file);
void ShowHashing(HASHING *H,void (*f)(void *),char *type,char *log_file);
void *PesquisarHashing(HASHING *H,void (*f)(void *,void *,void *),void *word,char *log_file);


#endif // HASHING_H_INCLUDED
