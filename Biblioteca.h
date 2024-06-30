#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Hashing.h"
#include "Lista.h"


typedef struct
{
    char *NOME;
    char FICHEIRO_LOGS[50];

    HASHING *HLivros;
    LISTA   *LPessoas;
    LISTA   *LRequisicoes;
    LISTA   *LDistritos;
    LISTA   *LConcelhos;
    LISTA   *LFreguesias;
}BIBLIOTECA;

BIBLIOTECA *CriarBiblioteca(char *_nome, char *_logs);
void ShowBiblioteca(BIBLIOTECA *B);
void DestruirBiblioteca(BIBLIOTECA *B);
void ImportPessoas(BIBLIOTECA *B);
void ImportConselhos(BIBLIOTECA *B);
void ImportDistritos(BIBLIOTECA *B);
int LoadFicheiroBiblioteca(BIBLIOTECA *B);


#endif // BIBLIOTECA_H_INCLUDED
