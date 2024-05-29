#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int ISBN;
    char *TITULO;
    char *AUTOR;
    char *AREA;
    int ANO_PLUBLICACAO;
}LIVRO;

LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor, int _ano_pub );
void MostrarLivro(LIVRO *P);
void DestruirLivro(LIVRO *P);


#endif // LIVRO_H_INCLUDED
