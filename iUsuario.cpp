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
