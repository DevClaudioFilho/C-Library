#ifndef REQUISICAO_H_INCLUDED
#define REQUISICAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Pessoa.h"
#include "Livro.h"


typedef struct
{
    int ID;
    PESSOA *Ptr_Req;
    LIVRO *Ptr_Livro;
    DATA *Data_Requisicao;
    DATA *Data_Devolucao;
}REQUISICAO;

int MenuRequisicao();
char PainelRequisicao(BIBLIOTECA *BRequisicao);
REQUISICAO *CriarRequisicao(int _id, PESSOA *P, LIVRO *L,char *log_file);
void MostrarRequisicao(REQUISICAO *R,char *log_file);
void DestruirRequisicao(REQUISICAO *R,char *log_file);
int PesquisarRequisicao(REQUISICAO *L, int _id,char *log_file );
int PesquisarRequisicaoPessoa(REQUISICAO *L, int _id,char *log_file );
int PesquisarRequisicaoAtiva(REQUISICAO *L, int _id );
int PesquisarRequisicaoFechada(REQUISICAO *L, int _id );
LIVRO *LivroMaisRequisitadoBiblioteca(LISTA* LReq, char* log_file);
LIVRO* AreaMaisRequisitadoBiblioteca(LISTA* LReq, char* log_file);
char *AreaMaisComum(LISTA* LReq, char* log_file);

#endif // REQUISICAO_H_INCLUDED
