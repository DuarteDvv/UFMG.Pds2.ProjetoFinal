#include "Usuario.hpp"
#include <list>

void Usuario::setUsuario(std::string nome, int cpf){ //Aloca os dados e verifica se já existe
    if (!função de busca em lista){
        this->nome = nome;
        this->cpf = cpf;
        std::cout << "Cliente registrado" << std::endl;
    }
    else{
        std::cout << "Cliente já existe" << std::endl;
    }
}
