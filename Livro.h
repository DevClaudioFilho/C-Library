#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Hashing.h"

typedef struct
{
    int ISBN;
    char *TITULO;
    char *AUTOR;
    char *AREA;
    int ANO_PLUBLICACAO;
}LIVRO;

LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor,char *_area ,int _ano_pub );
void MostrarLivro(LIVRO *L);
void DestruirLivro(LIVRO *L);
int PesquisarLivro(LIVRO *L, int ISBN);
int OrdenarLivros(LIVRO *a, LIVRO *b,int sw);


#endif // LIVRO_H_INCLUDED
