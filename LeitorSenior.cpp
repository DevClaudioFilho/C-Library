#include "LeitorSenior.h"

LeitorSenior::LeitorSenior(int novoId,string novoNome, int novaIdade)
:Leitor(novoId,novoNome, novaIdade) {}

void LeitorSenior::Show() {
    cout<<"ID= "<<getId()<<endl;
    cout<<"Nome= "<<getNome()<<endl;
    cout<<"Idade= "<<getIdade()<<endl;
    cout<<"Tipo= Estudante"<<endl;
    cout<<"Prazo Maximo= "<<getPrazoMaximo()<<endl;
    cout<<"Taxa Multa= "<<getTaxaMulta()<<endl;
    cout<<"\n"<<endl;
};

void LeitorSenior::Edit() {
    string novoNome;
    int novaIdade,novoAutor,novaArea;

    cout << "Digite um novo nome: ";
    cin >> novoNome;
    setNome(novoNome);

    cout << "Digite um nova idade: ";
    cin >> novaIdade;
    setIdade(novaIdade);

    cout<<"\n"<<endl;
};

LeitorSenior::~LeitorSenior() {}
