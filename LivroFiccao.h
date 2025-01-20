#ifndef LIVROFICCAO_H
#define LIVROFICCAO_H

#include "Livro.h"

#include <string>
#include <iostream>

using namespace std;

class LivroFiccao:public Livro {
  public:
    // Construtor
    LivroFiccao(int id,string titulo, string autor, string genero);

    // Destruidor virtual para suporte a herança
    virtual ~LivroFiccao();

    // Métodos de acesso
    void Show();
    string getGenero() { return genero; }
    int getIdTipo() { return idTipo; }

    // Métodos de modificação
    void Edit();
    void setGenero(string novoGenero) {
     genero = novoGenero;
    }

    protected:
        int idTipo = 1;
        string genero;
};

#endif //LIVROFICCAO_H