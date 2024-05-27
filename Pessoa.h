#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int ID;
    char *NOME;
    char *CATEGORIA;
}PESSOA;

PESSOA *CriarPessoa(int _id, char *_nome, char *_categoria);
void MostrarPessoa(PESSOA *P);
void DestruirPessoa(PESSOA *P);
int PesquisarPessoa(PESSOA *P, char *palavra );
#endif // PESSOA_H_INCLUDED
