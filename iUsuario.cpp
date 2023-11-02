#include "Usuario.hpp"

void Usuario::setUsuario(std::string nome, std::string cpf) {
    this->nome = nome;
    this->cpf = cpf;
}

std::string Usuario::getCPF(){
    return cpf;
}

std::string Usuario::getNome(){
    return nome;
}

int Usuario::getAcessos(){
    return acessos;
}

void Usuario::AcessAdd(){
    acessos++;
}
