#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"





int main(){
    std::list<Usuario> Banco_de_usuarios;
    Usuario User;
    std::string cmd;
    std::string CPFr;
    std::string NOMEr;
    

    while(std::cin >> cmd){
        if (cmd == "FS") {
            //salvar log
            break;
        }

        else if (cmd == "CC"){
            std::cout << "Digite o CPF" << std::endl;
            std::cin >> CPFr;
            std::cin.ignore();


            if(!verifica_cpf(CPFr)){
                std::cout << "ERRO: dados incorretos" << std::endl;
                break;           
            }
            else if(existeUsuario(Banco_de_usuarios,CPFr)){
                std::cout << "ERRO: CPF repetido" << std::endl;
                break;
            }
            
            std::cout << "Digite o NOME " << std::endl;
            std::getline(std::cin, NOMEr);

            if(!verifica_nome(NOMEr)){
                std::cout << "ERRO: dados incorretos" << std::endl;
                break;
            }

            User.setUsuario(NOMEr,CPFr);
            Banco_de_usuarios.push_back(User);

            std::cout << "Cliente " << CPFr << " cadastrado com sucesso" << std::endl;
        }

        else if(cmd == "RC"){
            std::cout << "Digite o CPF:" << std::endl;
            std::cin >> CPFr;
            if(existeUsuario(Banco_de_usuarios,CPFr)){
                removeUsuario(Banco_de_usuarios,CPFr);
            }
            else{
                std::cout << "ERRO: CPF inexistente" << std::endl;
                break;
            }
            std::cout << "Cliente " << CPFr << " removido com sucesso" << std::endl;
        }

        else if(cmd == "LC"){
            std::cout << "Quer listar por nome[N] ou cpf[C]" << std::endl;
            std::cin >> CPFr;
            
            if (CPFr == "N")
            {
                Banco_de_usuarios.sort(compN);
            }
            else if(CPFr == "C"){
                Banco_de_usuarios.sort(compC);
            }

            for(Usuario n : Banco_de_usuarios){
                std::cout << n.getCPF() << " " <<  n.getNome() << std::endl;
            }
        }

        
    }
  
}
