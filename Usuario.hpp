#ifndef USUARIO_
#define USUARIO_
#include <string>
#include <iostream>



Class Usuario{
    private:
    std::string nome;
    int cpf;

    Usuario(){
        this->nome = ' ';
        this->cpf = 0;
    }
    
    public:
    Usuario::setUsuario(std::string, int);
    Usuario::getUsuario(std::string);
    Usuario::getUsuario(int); //Sobrecarga
    Usuario::remUsuario();
    Usuario::impUsuario();
};

#endif USUARIO_
