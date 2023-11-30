#ifndef USUARIO_
#define USUARIO_

#include <string>
#include <iostream>
#include <list>
#include "Film.hpp"

class Usuario {
private:
    std::string nome;
    std::string cpf;
    int acessos;
    std::list<filme*> Carrinho;

public:
    // Construtor da classe Usuario, inicializa nome, cpf e acessos
    Usuario(std::string nome, std::string cpf) : nome(nome), cpf(cpf) {
        this->acessos = 1;
    } 

    // Destrutor da classe Usuario, libera a memória alocada para filmes no carrinho
    ~Usuario() {
        for (auto* filmePtr : Carrinho) {
            delete filmePtr;
        }
        Carrinho.clear();
    }
    
    // Métodos de acesso aos membros privados
    std::string getCPF();
    std::string getNome(); 
    int getAcessos();

    // Método para adicionar acessos
    void AcessAdd(int);

    // Método para adicionar filme ao carrinho
    void addCarrinho(filme*);

    // Método para listar o conteúdo do carrinho
    void ListarCarrinho();

    // Método para gerar um recibo de compra
    void recibo(int &);
}; 

#endif
