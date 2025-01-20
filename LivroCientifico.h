#ifndef LIVROCIENTIFICO_H
#define LIVROCIENTIFICO_H

#include "Livro.h"

#include <string>
#include <iostream>


class LivroCientifico:public Livro {
    public:
        // Construtor
        LivroCientifico(int id, string titulo, string autor, string area);

        // Destruidor virtual para suporte a herança
        virtual ~LivroCientifico();

        // Métodos de acesso
        void Show();
        string getArea() { return area; }
        int getIdTipo() { return idTipo; }

        // Métodos de modificação
        void Edit();
        void setArea(string novaArea) {
            area = novaArea;
        }

    protected:
        int idTipo = 2;
        string area;
};



#endif //LIVROCIENTIFICO_H
