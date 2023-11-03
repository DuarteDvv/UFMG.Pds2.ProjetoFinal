#ifndef USUARIO_
#define USUARIO_
#include <string>
#include <iostream>
#include <list>


class Usuario{
    private:
        std::string nome;
        std::string cpf;
        int acessos;
    
     public:
        Usuario(){
            this->nome = {};
            this->cpf = {};
            this->acessos = 1;
        } 
        
        
        void setUsuario(std::string, std::string);
        std::string getCPF();
        std::string getNome(); 
        int getAcessos();
        void AcessAdd();

}; 
#endif