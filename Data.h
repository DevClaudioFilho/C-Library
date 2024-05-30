#ifndef Data_H_INCLUDED
#define Data_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    int DIA;
    int MES;
    int ANO;
}DATA;

DATA *CriarData(int _dia,int _mes,int _ano);
void MostrarData(DATA *D);
void DestruirData(DATA *D);
#endif // Data_H_INCLUDED
