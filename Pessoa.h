#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Biblioteca.h"
#include "Data.h"
#include "Lista.h"
#include "Uteis.h"

typedef struct
{
    int ID;
    char *NOME;
    DATA *NASCIMENTO;
    int ID_FREGUESIA;
}PESSOA;

int MenuPessoas();
//char PainelPessoa(BIBLIOTECA *BPess);
int verificarID(int ID_Pessoa,char *log_file);
int gerarID(char *log_file);
PESSOA *CriarPessoa(int _id, char *_nome, DATA *_nascimento, int _idfreguesia,char *log_file);
void MostrarPessoa(PESSOA *P,char *log_file);
int PesquisarPessoaId(PESSOA *P, int *_id,char *log_file);
int PesquisarPessoaNome(PESSOA *P, char *_nome,char *log_file);
void DestruirPessoa(PESSOA *P,char *log_file);
int OrdenarPessoas(PESSOA *a, PESSOA *b,int sw);
void MostrarPessoaSemReq(LISTA *P,LISTA *R,char *log_file);
void MostrarPessoaComReqAtivo(LISTA *P,LISTA *R,char *log_file);
char *ApelidoMaisComum(LISTA *P, char *log_file);
int calcularIdade(int dia, int mes, int ano);
int IdadeMaximaPessoa(LISTA *P,char *log_file);
int IdadeMediaPessoas(LISTA *P,char *log_file);
int NumMaiorIdade(LISTA *P,int _idadeCopm,char *log_file);
int NumPesDisNom(LISTA *P,int _idDis,char *_nome,char *log_file);


#endif // PESSOA_H_INCLUDED
