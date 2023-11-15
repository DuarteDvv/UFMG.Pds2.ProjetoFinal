#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"
#include "system.hpp"


int main()
{   

    Sistema sistema;

    
    std::string cmd, tipo, NomeDoArquivo;
    std::string NOMEr,CPFr;
    int cod, quantidade;

    std::cout << "Bem vindo ao sistema de locação" << std::endl
              << "Segue nossas opçoes de Serviços:" << std::endl;

    while (std::cin >> cmd)
    {

        if (cmd == "FS")
        {
            // salvar log
            break;
        }


        else if(cmd == "AL"){
            std::cin >> NomeDoArquivo;
            std::ifstream Arquivo(NomeDoArquivo);

            if (!Arquivo.is_open()) {
                std::cout << "Erro ao abrir o arquivo." << std::endl;
                return 1;
            }
            sistema.CadastrarFilmesDoArquivo(Arquivo);
        }

        

        else if (cmd == "CC")
        {
            std::cout << "Digite o CPF" << std::endl;
            std::cin >> CPFr;
            std::cin.ignore();

            if(!sistema.VerificarCpf(CPFr)){
                break;
            }

            std::cout << "Digite o NOME " << std::endl;
            std::getline(std::cin, NOMEr);

            if(!sistema.VerificarNome(NOMEr)){
                break;
            }    

            Usuario* user = new Usuario(NOMEr, CPFr);
            sistema.CadastrarCliente(user);

            std::cout << "Cliente " << CPFr << " cadastrado com sucesso" << std::endl;
        }



        else if (cmd == "RC")
        {
            std::cout << "Digite o CPF:" << std::endl;
            std::cin >> CPFr;

            if(!sistema.ExisteUsuario(CPFr)){
                std::cout << "ERRO: CPF inexistente" << std::endl;
                break;
            }
            
            sistema.RemoverCliente(CPFr);
            std::cout << "Cliente " << CPFr << " removido com sucesso" << std::endl;
        }



        else if (cmd == "LC")
        {
            std::cout << "Quer listar por nome[N] ou cpf[C]" << std::endl;
            std::cin >> CPFr;

            sistema.ListarCliente(CPFr);
        }




        else if (cmd == "CF")
        {
            std::cout << "Fita [F] ou DVD [D] ?" << std::endl;
            std::cin >> tipo;

            std::cout << "Quantos ?" << std::endl;
                std::cin >> quantidade;
            if(quantidade < 0){
                std::cout << "ERRO: dados incorretos" << std::endl;
            }

            std::cout << "Codigo" << std::endl;
            std::cin >> cod;
            if(cod < 0 || cod > 10000){
                std::cout << "O código deve estar entre 0 e 10 mil" << std::endl;
                break;
            }

            std::cin.ignore();

            if (sistema.ExisteFilme(cod))
            {
                std::cout << "ERRO: Código repetido" << std::endl;
                break;
            }

            std::cout << "Titulo ?" << std::endl;
            std::getline(std::cin, NOMEr);
            if (!verifica_titulo(NOMEr))
            {
                std::cout << "Titulo inválido" << std::endl;
                break;
            }




            if(tipo == "D"){
                std::cout << "categoria ?" << std::endl;
                std::cin >> CPFr;
                if (verifica_categoria(CPFr))
                {
                    CPFr = retorna_categoria(CPFr);
                    filme* d = new dvd(cod,NOMEr,quantidade,CPFr); 
                    sistema.CadastrarFilme(d);
                }
                else
                {
                    std::cout << "Categoria invalida" << std::endl;
                    break;
                }
            }

            else if(tipo == "F"){
                filme* fit = new fita(cod,NOMEr,quantidade);
                sistema.CadastrarFilme(fit);
            }

            std::cout << "Filme " << cod << " cadastrado com sucesso" << std::endl;
        }

    
  

        else if(cmd == "LF")
        {
            std::cout << "Listar por Titulo[T] ou por Codigo[C] ?" << std::endl;
            std::cin >> CPFr;
            
            sistema.ListarFilmes(CPFr);
        }



        else if (cmd == "RF")
        {
            std::cout << "Digite o Código:" << std::endl;
            std::cin >> cod;
            if(!sistema.ExisteFilme(cod)){
                std::cout << "ERRO: Código inexistente" << std::endl;
                break;
            }
            std::cout << "Filme " << cod << " removido com sucesso" << std::endl;
        }



        else if(cmd == "AL"){
            std::cout << "Digite o CPF" << std::endl;
            std::cin >> CPFr;
            if(sistema.ExisteUsuario(CPFr)){
                std::cout << "Digite o codigo dos filmes que deseja:" << std::endl;
                while(std::cin >> cod){
                    if(!sistema.ExisteFilme(cod)){
                        std::cout << "ERRO: Filme " << cod << " inexistente" << std::endl;
                        break;
                    }
                    if(cod == -1){
                        break;
                    }
                    sistema.AdicionarCarrinho(cod,CPFr);
                }
                sistema.ListarCompras(CPFr);
            }
            else{
                std::cout << "ERRO: CPF inexistente" << std::endl;
            }
        }



        else if(cmd == "DV"){
            std::cout << "Digite o CPF" << std::endl;
            std::cin >> CPFr;

            std::cout << "Quantidade de dias" << std::endl;
            std::cin >> cod;
            if(sistema.ExisteUsuario(CPFr)){
                sistema.Recibo(CPFr, cod);
            }
            else{
                std::cout << "ERRO: CPF inexistente" << std::endl;
            }
        }

        //
    }
}
