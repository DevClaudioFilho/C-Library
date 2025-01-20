#ifndef LEITORPROFESSOR_H
#define LEITORPROFESSOR_H

#include "Leitor.h"
#include <string>

using namespace std;

class LeitorProfessor:public Leitor {
    public:
        // Construtor
        LeitorProfessor(int id, string nome, int idade);

        // Destruidor virtual para suporte a herança
        virtual ~LeitorProfessor();

        // Métodos de acesso
        void Show();
        int getIdTipo(){ return idTipo;}
        int getPrazoMaximo(){ return prazoMaximo;}
        double getTaxaMulta() { return taxaMulta; }

        void Edit();

    protected:
        int idTipo = 3;
        int prazoMaximo = 20;
        double taxaMulta = 1.5;
};



#endif //LEITORPROFESSOR_H
