#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Data.h"

typedef struct
{
    int ID;
    char *NOME;
    DATA *NASCIMENTO;
    int ID_FREGUESIA
}PESSOA;

PESSOA *CriarPessoa(int _id, char *_nome, DATA *_nascimento, int _idfreguesia);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);
int PesquisarPessoa(PESSOA *P, char *palavra );
#endif // PESSOA_H_INCLUDED
