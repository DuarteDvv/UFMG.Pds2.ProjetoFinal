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
            this->acessos = 0;
        }
        
        
        void Usuario::setUsuario(std::string&, std::string&);

        std::string Usuario::getCPF();
        std::string Usuario::getNome(); 

        void Usuario::remUsuario(std::string);
        void Usuario::remUsuario(int); //Sobrecarga 

        void Usuario::impUsuario(std::string);
        void Usuario::impUsuario(int); //Sobrecarga teste
    
};

#endif USUARIO_
