#ifndef REQUISICAO_H_INCLUDED
#define REQUISICAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct
{
    int CODIGO;
    char *NOME;
}LOCAL;

LOCAL *CriarLocal(int _codigo, char *_nome,char *log_file);
int ValidaLocalCodigo(int _codigo,int _option,char *log_file);
void DestruirLocal(LOCAL *P,char *log_file);
int PesquisarLocalCodigo(LOCAL *P, int _codigo,char *log_file);
int PesquisarLocalNome(LOCAL *P, char *_nome,char *log_file);
void MostrarLocal(LOCAL *P,char *log_file);

#endif // REQUISICAO_H_INCLUDED
