#include "LivroRevista.h"

// Construtor
LivroRevista::LivroRevista(int novoId,string novoTitulo, string novoAutor, int novaEdicao)
: Livro(novoId,novoTitulo,novoAutor), edicao(novaEdicao){
    titulo = novoTitulo;
    autor = novoAutor;
    edicao = novaEdicao;
    idTipo=4;
};

void LivroRevista::Show() {
    cout<<"ID="<<getId()<<endl;
    cout<<"Titulo="<<getTitulo()<<endl;
    cout<<"Autor="<<getAutor()<<endl;
    cout<<"Edicao="<<getEdicao()<<endl;
    cout<<"Tipo= Revista-"<<getIdTipo()<<endl;
    cout<<"\n"<<endl;
};


void LivroRevista::Edit() {
    string novoTitulo,novoAutor;
    int novaEdicao;

    cout << "Digite um novo titulo: ";
    cin >> novoTitulo;
    setTitulo(novoTitulo);

    cout << "Digite um novo nome do autor: ";
    cin >> novoAutor;
    setAutor(novoAutor);

    cout << "Digite uma nova nivel de ensino: ";
    cin >> novaEdicao;
    setEdicao(novaEdicao);

    cout<<"\n"<<endl;
};

LivroRevista::~LivroRevista() {}