#ifndef LEITORCOMUM_H
#define LEITORCOMUM_H

#include "Leitor.h"

#include <string>

class LeitorComum:public Leitor {
    public:
        // Construtor
        LeitorComum(int id, string nome, int idade);

        // Destruidor virtual para suporte a herança
        virtual ~LeitorComum();

        // Métodos de acesso
        void Show();
        int getIdTipo(){ return idTipo;}
        int getPrazoMaximo(){ return prazoMaximo;}
        double getTaxaMulta() { return taxaMulta; }


        void Edit();

    protected:
        int idTipo = 1;
        int prazoMaximo = 20;
        double taxaMulta = 2.0;
};



#endif //LEITORCOMUM_H
