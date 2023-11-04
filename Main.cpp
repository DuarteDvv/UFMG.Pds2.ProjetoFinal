#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"






int main(){
    std::list<Usuario> Banco_de_usuarios;
    std::list<filme*> Catalogo;
    Usuario User;
    std::string cmd, tipo;
    std::string CPFr;
    std::string NOMEr;
    int cod, quantidade;
    
    std::cout << "Bem vindo ao sistema de locação" << std::endl << "Segue nossas opçoes de Serviços:" << std::endl;

    

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
                std::cout << "||" << n.getCPF() <<"|| " << ">> " <<  n.getNome() << std::endl;
            }
        }

        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        else if(cmd == "CF"){
            std::cout << "Fita [F] ou DVD [D] ?" << std::endl;
            std::cin >> tipo;

            if(tipo == "D"){
                dvd* DVD = new(dvd);

                std::cout << "Quantos ?" << std::endl;
                std::cin >> quantidade;

                std::cout << "Codigo" << std::endl;
                std::cin >> cod;
                std::cin.ignore();
                if(ExisteFilme(Catalogo,cod)){
                    std::cout << "ERRO: Código repetido" << std::endl;
                    break;
                }

                std::cout << "Titulo" << std::endl;
                std::getline(std::cin,NOMEr);

                std::cout << "categoria" << std::endl;
                std::cin >> CPFr;

                DVD->setFilme(quantidade,cod,NOMEr,CPFr);
                Catalogo.push_back(DVD);

                std::cout << "Filme " << cod << " cadastrado com sucesso"<<std::endl;

            }
            else if(tipo == "F"){
                fita* FITA = new fita;

                std::cout << "Quantos ?" << std::endl;
                std::cin >> quantidade;

                std::cout << "Codigo" << std::endl;
                std::cin >> cod;
                std::cin.ignore();
                if(ExisteFilme(Catalogo,cod)){
                    std::cout << "ERRO: Codigo repetido" << std::endl;
                    break;
                }

                std::cout << "Titulo" << std::endl;
                std::getline(std::cin,NOMEr);

                FITA->setFilme(quantidade,cod,NOMEr);
                Catalogo.push_back(FITA);
                std::cout << "Filme " << cod << " cadastrado com sucesso"<<std::endl;
            }
        }
            
            
        else if(cmd == "LF"){
            std::cout << "Listar por Titulo[T] ou por Codigo[C] ?" << std::endl;
            std::cin >> CPFr;
            if(CPFr == "T"){
                Catalogo.sort(compT);
            }
            else if(CPFr == "C"){
                Catalogo.sort(compCf);
            }
            for(filme* n : Catalogo){
                std::cout << "||" << (n)->getCod() <<"|| " << ">> " <<  (n)->getTitulo() << std::endl;
            }
        }
          
        else if(cmd == "RF"){
            std::cout << "Digite o Código:" << std::endl;
            std::cin >> cod;
            if(ExisteFilme(Catalogo,cod)){
                removeFilme(Catalogo,cod);
            }
            else{
                std::cout << "ERRO: Código inexistente" << std::endl;
                break;
            }
            std::cout << "Filme " << cod << " removido com sucesso" << std::endl;
        }
        
    }
}
        

   

