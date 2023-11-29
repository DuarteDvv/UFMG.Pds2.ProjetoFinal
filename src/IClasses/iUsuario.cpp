#include "Usuario.hpp"

std::string Usuario::getCPF()
{
    return this->cpf;
}

std::string Usuario::getNome(){
    return this->nome;
}

int Usuario::getAcessos(){
    return acessos;
}

void Usuario::AcessAdd(int n){
    this->acessos += n;
}

void Usuario::addCarrinho(filme* film){
    this->Carrinho.push_back(film);
}

void Usuario::ListarCarrinho(){
    for (auto itt = this->Carrinho.begin(); itt != this->Carrinho.end(); ++itt){
        std::cout << (*itt)->getCod() << " " << (*itt)->getTitulo() << " " << (*itt)->getTipo() << std::endl;
    }
}

void Usuario::recibo(int &dias){
    float total = 0;
    for (auto it = this->Carrinho.begin(); it != this->Carrinho.end(); ++it){
        (*it)->MaisUm();
        std::cout << (*it)->getCod() << " ";

        total += (*it)->CalcularPreco(dias);

        std::cout << "| " << (*it)->CalcularPreco(dias) << '$'<< std::endl;
    }
    if(this->getAcessos() >= 3){
        std::cout << "Total a pagar (desconto de 10% aplicado): " << total*0.9 << '$' << std::endl;

    }
    else{
        std::cout << "Total a pagar: " << total << '$' << std::endl;
    }

    for (auto* filmePtr : Carrinho) {
            delete filmePtr;
    }
    Carrinho.clear();
}

   
