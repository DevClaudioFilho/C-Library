#include "LivroCientifico.h"

// Construtor
LivroCientifico::LivroCientifico(int novoID,string novoTitulo, string novoAutor, string novaArea)
: Livro(novoID,novoTitulo,novoAutor), area(novaArea){
    id= novoID;
    titulo = novoTitulo;
    autor = novoAutor;
    area = novaArea;

};

void LivroCientifico::Show() {
    cout<<"Id="<<getId()<<endl;
    cout<<"Titulo="<<getTitulo()<<endl;
    cout<<"Autor="<<getAutor()<<endl;
    cout<<"Area="<<getArea()<<endl;
    cout<<"Tipo= Cientifico-"<<getIdTipo()<<endl;
    cout<<"\n"<<endl;
};

void LivroCientifico::Edit() {
    string novoTitulo,novoAutor,novaArea;

    cout << "Digite um novo titulo: ";
    cin >> novoTitulo;
    setTitulo(novoTitulo);

    cout << "Digite um novo nome do autor: ";
    cin >> novoAutor;
    setAutor(novoAutor);

    cout << "Digite uma nova area: ";
    cin >> novaArea;
    setArea(novaArea);

    cout<<"\n"<<endl;
};



LivroCientifico::~LivroCientifico() {}