
#include "Lista.h"

//--------------------------------------------------
/** \brief Permite alocar mem�ria para uma lista
 *
 * \return LISTA* : Retorna a lista alocada
 * \date 10/04/2024
 * \author Docentes de ED
 */
LISTA *CriarLista()
{
    LISTA *L = (LISTA *)malloc(sizeof(LISTA));
    L->NEL = 0;
    L->Inicio = NULL;
    return L;
}

void AddLista(LISTA *L, void *X)
{
    if (!L) return;
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;
}

void ShowLista(LISTA *L, void (*f)(void *))
{
    if (!L) return;
    if (!L->Inicio) return;
    NO *P = L->Inicio;
    while (P)
    {
        f(P->Info);
        P = P->Prox;
    }
}

void *PesquisarLista(LISTA *L, int (*fcomp)(void *, void *), void *palavra)
{
    if (!L) return NULL;
    NO *P = L->Inicio;
    while (P)
    {
        if (fcomp(P->Info, palavra) == 1)
            return P->Info;
        P = P->Prox;
    }
    return NULL;
}

void RemoverLista(LISTA *L, void *VInfo)
{
    NO *atual = L->Inicio;
    NO *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->Info == VInfo)
        {
            if (anterior == NULL)
            {
                L->Inicio = atual->Prox;
            }
            else
            {
                anterior->Prox = atual->Prox;
            }

            free(atual);
            L->NEL--;
            return;
        }

        anterior = atual;
        atual = atual->Prox;
    }

    printf("Valor n�o encontrado na lista.\n");
}


void DestruirLista(LISTA *L)
{
    //printf("Implementar <%s>\n", __FUNCTION__);
    if (!L) return;
    NO *Martim;
    NO *Helder = L->Inicio;
    while (Helder)
    {
        Martim = Helder->Prox;
        DestruirPessoa(Helder->Info);
        free (Helder);
        Helder = Martim;
    }
    free(L);
    L->NEL--;
}


int SizeLista(LISTA *L)
{
    if (!L) return -1;
    return L->NEL;
}

void bubbleSort(LISTA *lista,int (*f)(void *,void *,void *),int sw)
{
    int i, j;
    NO *atual;
    NO *proximo;

    for (i = 0; i < lista->NEL - 1; i++)
    {
        atual = lista->Inicio;
        proximo = atual->Prox;

        for (j = 0; j < lista->NEL - i - 1; j++)
        {
            if( f(atual->Info,proximo->Info,sw) == 1){
                void *temp = atual->Info;
                atual->Info = proximo->Info;
                proximo->Info = temp;
            }

            atual = atual->Prox;
            proximo = proximo->Prox;
        }
    }
}
