#include "Data.h"

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
    int validado=0;
    if(1<_dia && 31>_dia){
        return 1;
    };
    if(1<_mes && 12>_mes && validado==1){
        validado=1;
    }
    else{
        validado=0;
    }

    if(_ano>0 && validado==1){
        return 1;
    }
    return 0;
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
    if(!D->DIA) return NULL;
    if(D->DIA<10 && D->MES<10){
        printf(" 0%d-0%d-%d\n", D->DIA, D->MES, D->ANO);
    }
    else if(D->DIA<10 && D->MES>10){
        printf(" 0%d-%d-%d\n", D->DIA, D->MES, D->ANO);
    }
    else if(D->DIA>10 && D->MES<10){
        printf(" %d-0%d-%d\n", D->DIA, D->MES, D->ANO);
    }
    else{
        printf(" %d-%d-%d\n", D->DIA, D->MES, D->ANO);
    }
}

void DestruirData(DATA *D)
{
    if(!D)return;
    free(D);
}
