#include "Usuario.hpp"
#include "Film.hpp"




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





            std::cout << "Digite o NOME " << std::endl;
            std::getline(std::cin, NOMEr);
            std::cin.ignore();

        User.setUsuario(NOMEr, CPFr);
        Banco_de_usuarios.push_back(User);
        


        }
    }
  
}
