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

void Usuario::AcessAdd(){
    this->acessos++;
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
        std::cout << (*it)->getCod() << " ";
        if((*it)->getTipo() == "DVD"){

            dvd* D = dynamic_cast<dvd*>(*it);
            if(D->isEstoque()){
                total += 10*dias;
                std::cout << dias << "x10 = " << dias*10 << std::endl;


            }
            else if(D->isPromo()){
                total += 10;
                std::cout << "10" << std::endl;


            }
            else if(D->isLanca()){
                total += 20*dias;
                std::cout << dias << "x20 = " << dias*20 << std::endl;
            }
        }
        else{

            fita* F = dynamic_cast<fita*>(*it);

            if(F->isRebobinado()){
                total += 5;
                std::cout << "5" << std::endl;


            }
            else{
                total += 7;
                std::cout << "7" << std::endl;
            }

        }
    }

    std::cout << "Total a pagar: " << total << std::endl;
}