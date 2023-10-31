#include "Usuario.hpp"
#include "Film.hpp"


int main(){
    std::string cmd;
    int CPFr;
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


        }
    }
  
}
