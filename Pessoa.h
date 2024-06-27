#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Data.h"

typedef struct
{
    int ID;
    char *NOME;
    DATA *NASCIMENTO;
    int ID_FREGUESIA;
}PESSOA;

PESSOA *CriarPessoa(int _id, char *_nome, DATA *_nascimento, int _idfreguesia,char *log_file);
void MostrarPessoa(PESSOA *P,char *log_file);
void DestruirPessoa(PESSOA *P,char *log_file);
int PesquisarPessoa(PESSOA *P, char *palavra,char *log_file);
int OrdenarPessoas(PESSOA *a, PESSOA *b,int sw);
#endif // PESSOA_H_INCLUDED
