#ifndef LIVRO_H_INCLUDED
#define LIVRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Uteis.h"
#include "Biblioteca.h"


typedef struct
{
    int ISBN;
    char *TITULO;
    char *AUTOR;
    char *AREA;
    int ANO_PLUBLICACAO;
}LIVRO;

int MenuLivro();
LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor,char *_area, int _ano_pub,char *log_file );
void MostrarLivro(LIVRO *P,char *log_file);
void DestruirLivro(LIVRO *P,char *log_file);
int PesquisarLivro(LIVRO *L, int _isbn,char *log_file );
void LivroMaisRecente(HASHING *H,char *file_log);


#endif // LIVRO_H_INCLUDED
