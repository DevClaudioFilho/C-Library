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

void AddLista(LISTA *L, void *X,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!L) return;
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->Info = X;
    aux->Prox = L->Inicio;
    L->Inicio = aux;
    L->NEL++;

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

void ShowLista(LISTA *L, void (*f)(void *),char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!L) return;
    if (!L->Inicio) return;
    NO *P = L->Inicio;
    while (P)
    {
        f(P->Info);
        P = P->Prox;
    }

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

void *PesquisarLista(LISTA *L, int (*fcomp)(void *, void *,void *), void *palavra,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!L) return NULL;
    NO *P = L->Inicio;
    while (P)
    {
        if (fcomp(P->Info, palavra,log_file) == 1)
            return P->Info;
        P = P->Prox;
    }

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    return NULL;
}

void RemoverLista(LISTA *L, void *VInfo,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

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

            //free(atual);
            L->NEL--;

            fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
            fclose(F_Logs);
            return;
        }

        anterior = atual;
        atual = atual->Prox;
    }

    printf("Valor nao encontrado na lista.\n");

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

void DestruirLista(LISTA *L,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!L) return;
    NO *proxNO;
    NO *noInicio = L->Inicio;
    while (noInicio)
    {
        proxNO = noInicio->Prox;
        free (noInicio);
        noInicio = proxNO;
    }
    free(L);
    L->NEL--;

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}

int SizeLista(LISTA *L,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

    if (!L) return -1;

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
    return L->NEL;
}

void bubbleSort(LISTA *lista,int (*f)(void *,void *,void *),int sw,char *log_file)
{
    FILE *F_Logs = fopen(log_file, "a");
    time_t now = time(NULL) ;
    fprintf(F_Logs, "Entrei em %s na data %s\n", __FUNCTION__, ctime(&now));

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

    fprintf(F_Logs, "Terminou %s na data %s\n", __FUNCTION__, ctime(&now));
    fclose(F_Logs);
}
