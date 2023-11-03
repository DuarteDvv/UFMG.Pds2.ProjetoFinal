#include "Film.hpp"
#include <ctime>

bool fita::isRebobinado(){
    std::srand(static_cast<unsigned>(std::time(0))); //Torna mais aleatorio

    int Randombool = rand() % 2; // de 0 a N-1 | N = 2
    if(Randombool == 1){
        return true;
    }
    else{
        return false;
    }
}

void dvd::setFilme(int q,int cod,std::string nome,std::string cat){

    filme::setFilme(q,cod,nome);

    if(cat == "Estoque"){
        this->estoque = true;
    }
    else if(cat == "Promocao"){
        this->promocao = true;
    }
    else if(cat == "lancamento"){
        this->lancamento = true;
    }

 }
 void filme::setFilme(int q,int cod,std::string nome){
    this->quantidade = q;
    this->codigo = cod;
    this->titulo = nome;
 }

 int filme::getCod(){
    return this->codigo;
 }

 int filme::getQuantidade(){
    return this->quantidade;
 }

 std::string filme::getTitulo(){
    return this->titulo;
 }

 bool dvd::isEstoque(){
    return this->estoque;
 }
 bool dvd::isLanca(){
    return this->lancamento;
 }
 bool dvd::isPromo(){
    return this->promocao;
 }
