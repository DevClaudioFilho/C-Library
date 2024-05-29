#include "Livro.h"

LIVRO *CriarLivro(int _isbn, char *_titulo, char *_autor, int _ano_pub )
{
    LIVRO *P = (LIVRO *)malloc(sizeof(LIVRO));
    P->ISBN = _isbn;
    P->TITULO = (char *)malloc((strlen(_titulo) + 1)*sizeof(char));
    strcpy(P->TITULO, _titulo);
    P->AUTOR = (char *)malloc((strlen(_autor) + 1)*sizeof(char));
    strcpy(P->AUTOR, _autor);
    P->ANO_PLUBLICACAO = _ano_pub;
    return P;
}
void MostrarLivro(LIVRO *P)
{
    printf("\tPESSOA: ID: %d [%s] [%d]\n", P->ISBN, P->TITULO, P->ANO_PLUBLICACAO);
}
void DestruirLivro(LIVRO *P)
{
    free (P->TITULO);
    free (P->AUTOR);
    free (P);
}
