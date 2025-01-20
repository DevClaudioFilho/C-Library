#include "LivroEducativo.h"


// Construtor
LivroEducativo::LivroEducativo(int novoId, string novoTitulo, string novoAutor, string novoNivelEnsino)
: Livro(novoId,novoTitulo,novoAutor), nivelEnsino(novoNivelEnsino){
    id = novoId;
    titulo = novoTitulo;
    autor = novoAutor;
    nivelEnsino = novoNivelEnsino;
    idTipo=3;
};

void LivroEducativo::Show() {
    cout<<"ID="<<getId()<<endl;
    cout<<"Titulo="<<getTitulo()<<endl;
    cout<<"Autor="<<getAutor()<<endl;
    cout<<"Nivel Ensino="<<getNivelEnsino()<<endl;
    cout<<"Tipo= Educativo-"<<getIdTipo()<<endl;
};

void LivroEducativo::Edit() {
    string novoTitulo,novoAutor,novoNivelEnsino;

    cout << "Digite um novo titulo: ";
    cin >> novoTitulo;
    setTitulo(novoTitulo);

    cout << "Digite um novo nome do autor: ";
    cin >> novoAutor;
    setAutor(novoAutor);

    cout << "Digite uma nova nivel de ensino: ";
    cin >> novoNivelEnsino;
    setNivelEnsino(novoNivelEnsino);

    cout<<"\n"<<endl;
};


LivroEducativo::~LivroEducativo() {}