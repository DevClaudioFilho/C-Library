#ifndef LEITORESTUDANTE_H
#define LEITORESTUDANTE_H

#include "Leitor.h"
#include <string>

using namespace std;

class LeitorEstudante:public Leitor {
    public:
        // Construtor
        LeitorEstudante(int id, string nome, int idade);

        // Destruidor virtual para suporte a herança
        virtual ~LeitorEstudante();

        // Métodos de acesso
        void Show();
        int getIdTipo(){ return idTipo;}
        int getPrazoMaximo(){ return prazoMaximo;}
        double getTaxaMulta() { return taxaMulta; }

        void Edit();


    protected:
        int idTipo = 2;
        int prazoMaximo = 30;
        double taxaMulta = 1.5;
};

#endif //LEITORESTUDANTE_H
