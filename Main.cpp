#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.h"




int main(){
    std::list<Usuario> Banco_de_usuarios;
    Usuario User;
    std::string cmd;
    std::string CPFr;
    std::string NOMEr;

    while(std::cin >> cmd){
        if (cmd == "FS") {

            break;
        }

        else if (cmd == "CC"){
            std::cout << "Digite o CPF" << std::endl;
            std::cin >> CPFr;

            if(!verifica_cpf(CPFr)){
                std::cout << "ERRO: dados incorretos" << std::endl;
                break;           
            }
            if(existeUsuario(Banco_de_usuarios,CPFr)){
                std::cout << "ERRO: CPF repetido" << std::endl;
                break;
            }
            
            std::cout << "Digite o NOME " << std::endl;
            std::getline(std::cin, NOMEr);
            std::cin.ignore();

            if(verifica_nome(NOMEr)){
                std::cout << "ERRO: dados incorretos" << std::endl;
                break;
            }

            User.setUsuario(CPFr,NOMEr);
            Banco_de_usuarios.push_back(User);

            std::cout << "Cliente " << CPFr << " cadastrado com sucesso" << std::endl;
        }

        else if(cmd == "RC"){
             removeUsuario(Banco_de_usuarios,CPFr);


     
     
     
        }
    }
  
}
