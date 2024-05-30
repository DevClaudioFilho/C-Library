#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"
#include "Hashing.h"
#include "Biblioteca.h"

/** \brief Permite Alocar e inicializar uma estrutura Data
 *
 * \param _dia int
 * \param _mes int
 * \param _ano int
 * \return DATA*
 *
 */

int ValidarData(int _dia, int _mes, int _ano)
{
    if(_mes<1 && 12>_mes){
        printf("Dia da data invalido");
        return 0;
    };

    if(_dia<1 && _dia>31){
        printf("Dia da data invalido");
        return 0;
    };
    return 1;
}


DATA *CriarData(int _dia, int _mes, int _ano)
{
    DATA *D = (DATA *)malloc(sizeof(DATA));
    D->DIA = _dia;
    D->MES = _mes;
    D->ANO = _ano;
    return D;
}

void MostrarData(DATA *D)
{
    printf(" %d/%d/%d\n", D->DIA, D->MES, D->ANO);
}

void DestruirData(DATA *D)
{
    free (D->DIA);
    free (D->MES);
    free (D->ANO);
    free (D);
}
