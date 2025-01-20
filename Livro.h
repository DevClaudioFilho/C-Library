#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <iostream>

using namespace std;

/**
 * @class Livro
 * @brief Classe base abstrata para diferentes tipos de livros.
 */

class Livro {
 public:
  // Construtor
  Livro(int id,string titulo, string autor);

  // Destruidor virtual para suporte a herança
  virtual ~Livro();

  // Metodos virtuais
  virtual void Show() = 0;
  virtual void Edit() = 0;
  virtual int getIdTipo() = 0;


  // Métodos de acesso

  string getTitulo(){ return titulo; }
  string getAutor() { return autor; }
  int getId() { return id; }

  // Métodos de modificação
  void setTitulo(string novoTitulo) {
   titulo = novoTitulo;
  }

  void setAutor(string novoAutor) {
   autor = novoAutor;
  }

  void setID(int novoId) {
    id = novoId;
  }

  void setIdTipo(int novoIdTipo) {
    idTipo = novoIdTipo;
   }



 protected:
  int id;
  string titulo;
  string autor;
  int idTipo;
};

#endif // LIVRO_H
