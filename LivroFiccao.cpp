#include "LivroFiccao.h"

// Construtor
LivroFiccao::LivroFiccao(int novoId,string novoTitulo, string novoAutor, string novoGenero)
: Livro(novoId,novoTitulo,novoAutor), genero(novoGenero){
    titulo = novoTitulo;
    autor = novoAutor;
    genero = novoGenero;
    idTipo=novoId;
};

void LivroFiccao::Show() {
    cout<<"ID="<<getId()<<endl;
    cout<<"Titulo="<<getTitulo()<<endl;
    cout<<"Autor="<<getAutor()<<endl;
    cout<<"Genero="<<getGenero()<<endl;
    cout<<"Tipo= Ficcao-"<<getIdTipo()<<endl;
    cout<<"\n"<<endl;
};

void LivroFiccao::Edit() {
    string novoTitulo,novoAutor,novoGenero;

    cout << "Digite um novo titulo: ";
    cin >> novoTitulo;
    setTitulo(novoTitulo);

    cout << "Digite um novo nome do autor: ";
    cin >> novoAutor;
    setAutor(novoAutor);

    cout << "Digite uma nova genero: ";
    cin >> novoGenero;
    setGenero(novoGenero);

    cout<<"\n"<<endl;
};



LivroFiccao::~LivroFiccao() {}