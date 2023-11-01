#include "Usuario.hpp"

std::string Usuario::getCPF(){
    return this->cpf;

}

std::string Usuario::getNome(){
    return this->nome;
}

void Usuario::setUsuario(std::string &cpf, std::string &nome){
    this->cpf = cpf;
    this->nome = nome;
}
