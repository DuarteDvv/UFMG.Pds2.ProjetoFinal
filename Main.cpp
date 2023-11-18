// g++ -o arq Main.cpp Usuario.hpp iUsuario.cpp iFilm.cpp  Film.hpp system.hpp isystem.cpp IFunction.cpp functions.hpp 
#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"
#include "system.hpp"
#include <cassert>
#include <exception>


int main()
{   

    Sistema sistema;

    
    std::string cmd, tipo, NomeDoArquivo;
    std::string NOMEr,CPFr;
    int cod, quantidade;


    sistema.LoadData();
    sistema.AnimCarregarDados();
    
    std::cout << "Bem vindo ao sistema de locacao" << std::endl << std::endl
    << "Segue nossas opcoes de Servicos:" << std::endl << std::endl
    << "CC - Cadastrar Cliente" << "|  RC - Remover Clientes" << std::endl 
    << "LC - Listar Clientes" << "|  LA - Ler Arquivo" << std::endl 
    << "CF - Cadastrar Filme" << "|  RF - Remover Filme" << std::endl 
    << "LF - Listar Filme" << "|  AL - Alugar Filme" << std::endl 
    << "DV - Devolucao" << "|  FS - Finalizar" << std::endl
    << "OE - Opcoes de Estoque" << "|  RA - Registros De Alugueis" << std::endl;

    while (std::cin >> cmd)
    {   
        LimparTela();
        cmd = padroniza_entrada(cmd);
        try{
            if (cmd == "FS") 
            {
                sistema.AnimacaoEscolha();
                sistema.SaveData();
                sistema.animacaoSalvando();
                break;
            }


            else if(cmd == "LA"){
                sistema.AnimacaoEscolha();
                std::cout << "Digite o nome do arquivo" << std::endl;
                std::cin >> NomeDoArquivo;
                std::ifstream Arquivo(NomeDoArquivo);

                assert(Arquivo.is_open() && "ERRO na abertura do aquivo");

                sistema.CadastrarFilmesDoArquivo(Arquivo);
            }

            

            else if (cmd == "CC")
            {
                
                sistema.AnimacaoEscolha();
                std::cout << "Digite o CPF" << std::endl;
                std::cin >> CPFr;

                try{
                    if(!sistema.VerificarCpf(CPFr)){
                        throw std::invalid_argument("CPF invalido - Digite um valido");
                    }

                }catch(const std::invalid_argument &e){

                    std::cout << e.what() << std::endl;
                    sistema.TratarCPF(CPFr);
                }

                LimparTela();

                std::cin.ignore();

                std::cout << "Digite o NOME " << std::endl;
                std::getline(std::cin, NOMEr);

                try{
                    if(!sistema.VerificarNome(NOMEr)){
                        throw std::invalid_argument("NOME invalido - Digite um valido");
                    }

                }catch(const std::invalid_argument &e){
                    
                    std::cout << e.what() << std::endl;
                    sistema.TratarNome(NOMEr);
                }

                Usuario* user = new Usuario(NOMEr, CPFr);
                sistema.CadastrarCliente(user);

                std::cout << "Cliente " << CPFr << " cadastrado com sucesso" << std::endl;
            
                
            }




            else if (cmd == "RC")
            {
                sistema.AnimacaoEscolha();
                std::cout << "Digite o CPF:" << std::endl;
                std::cin >> CPFr;

                try{
                    if(!sistema.ExisteUsuario(CPFr)){
                        throw std::invalid_argument("CPF não encontrado - digite novamente");
                    }
                } catch(const std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarExistenciaU(CPFr);
                    
                }
                sistema.RemoverCliente(CPFr);
                std::cout << "Cliente " << CPFr << " removido com sucesso" << std::endl;
            }



            else if (cmd == "LC")
            {
                sistema.AnimacaoEscolha();
                std::cout << "Quer listar por nome[N] ou cpf[C]" << std::endl;
                std::cin >> CPFr;
                try{
                    if(CPFr != "C" && CPFr != "N"){
                        throw std::invalid_argument("Entrada invalida - Digite novamente");
                    }
                } catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarListagemU(CPFr);
                }

                sistema.ListarCliente(CPFr);
            }




            else if (cmd == "CF")
            {
                sistema.AnimacaoEscolha();
                std::cout << "Fita [F] ou DVD [D] ?" << std::endl;
                std::cin >> tipo;

                try{
                    if(tipo != "C" && tipo != "N"){
                        throw std::invalid_argument("Entrada invalida - Digite novamente");
                    }
                } catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarTIPO(tipo);
                }

                std::cout << "Quantos ?" << std::endl;
                std::cin >> quantidade;
                try{
                    if(quantidade < 0){
                        throw std::invalid_argument("Quantidade tem que ser maior que 0 - Digite novamente");
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarQuantidade(quantidade);
                }

                std::cout << "Codigo" << std::endl;
                std::cin >> cod;
                try{
                    if(cod < 0 || cod > 10000){
                        throw std::invalid_argument("Quantidade tem que ser maior que 0 e menor que 10000- Digite novamente");
                    }
                    else if(sistema.ExisteFilme(cod)){

                        throw std::invalid_argument("Filme Já cadastrado- Digite novamente");
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarCod(cod);
                }

                std::cin.ignore();

                std::cout << "Titulo " << std::endl;
                std::getline(std::cin, NOMEr);
                try{
                    if (!sistema.VerificaTitulo(NOMEr))
                    {
                        throw std::invalid_argument("Apenas Alfanumericos- Digite novamente");
                    
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarTitulo(NOMEr);
                }

                if(tipo == "D"){
                    std::cout << "categoria ? [lacamento, estoque ou promocao]" << std::endl;
                    std::cin >> CPFr;
                    try{
                        if (!verifica_categoria(CPFr))
                        {
                            throw std::invalid_argument("Categoria invalida- Digite novamente");    
                        }
                        
                    }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarCat(CPFr);
                    }

                    CPFr = retorna_categoria(CPFr);
                    filme* d = new dvd(cod,NOMEr,quantidade,CPFr); 
                    sistema.CadastrarFilme(d);
                }

                else if(tipo == "F"){
                    
                    filme* fit = new fita(cod,NOMEr,quantidade);
                    sistema.CadastrarFilme(fit);
                }

                std::cout << "Filme " << cod << " cadastrado com sucesso" << std::endl;
            }

        
    

            else if(cmd == "LF")
            {
                sistema.AnimacaoEscolha();
                std::cout << "Listar por Titulo[T] ou por Codigo[C] ?" << std::endl;
                std::cin >> CPFr;
                try{
                    if(CPFr != "T" && CPFr != "C"){
                        throw std::invalid_argument("Entrada invalida- Digite novamente");
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarListagemF(CPFr);
                }
                
                sistema.ListarFilmes(CPFr);
            }



            else if (cmd == "RF")
            {
                sistema.AnimacaoEscolha();
                std::cout << "Digite o Código:" << std::endl;
                std::cin >> cod;
                 try{
                    if(cod < 0 || cod > 10000){
                        throw std::invalid_argument("Quantidade tem que ser maior que 0 e menor que 10000- Digite novamente");
                    }
                    else if(!sistema.ExisteFilme(cod)){

                        throw std::invalid_argument("Filme Não existe- Digite novamente");
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarCodN(cod);
                }
                std::cout << "Filme " << cod << " removido com sucesso" << std::endl;
            }



            else if(cmd == "AL"){
                sistema.AnimacaoEscolha();
                std::cout << "Digite o CPF" << std::endl;
                std::cin >> CPFr;
                try{
                    if(!sistema.ExisteUsuario(CPFr)){
                        throw std::invalid_argument("CPF não encontrado - digite novamente");
                    }
                } catch(const std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarExistenciaU(CPFr);
                    
                }
                std::cout << "Digite o codigo dos filmes que deseja:" << std::endl;
                while(std::cin >> cod){
                    if(cod == -1){
                        break;
                    }
                    try{
                    if(cod < -1 || cod > 10000){
                        throw std::invalid_argument("Quantidade tem que ser maior que 0 e menor que 10000- Digite novamente");
                    }
                    else if(!sistema.ExisteFilme(cod)){

                    throw std::invalid_argument(" filme inexistente- Digite novamente"); //tratar cod revisar
                    }
                    }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarCodN(cod);
                    }

                    sistema.AdicionarCarrinho(cod,CPFr);
                }
                sistema.ListarCompras(CPFr);
                
                
            }



            else if(cmd == "DV"){
                sistema.AnimacaoEscolha();
                std::cout << "Digite o CPF" << std::endl;
                std::cin >> CPFr;
                try{
                    if(!sistema.ExisteUsuario(CPFr)){
                        throw std::invalid_argument("CPF não encontrado - digite novamente");
                    }
                } catch(const std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarExistenciaU(CPFr);
                }

                std::cout << "Quantidade de dias" << std::endl;
                std::cin >> cod;

                try{
                    if(quantidade < 0){
                        throw std::invalid_argument("Os dias tem que ser maior que 0 - Digite novamente");
                    }
                }catch(std::invalid_argument &e){
                    std::cout << e.what() << std::endl;
                    sistema.TratarQuantidade(cod);
                }

                sistema.Recibo(CPFr, cod);
            }

            else if(cmd =="RA"){
                sistema.RegistroDeAlugays();
            }

            else if(cmd == "OE"){
                std::string Senha = "user";
                int tentativas = 0;
                std::cout << "Essa opcao e exclusiva para ADM" << std::endl << "Digite a senha [4 Digitos]: " << std::endl;
                std::cin >> CPFr;
                while(CPFr != Senha){
                     try{
                        if(CPFr.length() != 4){
                            throw std::invalid_argument("Senha deve conter 4 digitos - digite novamente");
                        }
                    } catch(const std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarSenha(CPFr);
                        if(CPFr == Senha){
                            break;
                        }
                    }


                    tentativas++;
                    std::cout << "Senha errada! " << 5 - tentativas << " Tentativas restantes" << std::endl;
                    std::cin >> CPFr;
                   
                    if(tentativas == 5){
                        break;
                    }
                }
                if(tentativas == 5){
                    break;
                }

                LimparTela();

                std::cout << "LE - Listar Estoque" << std::endl << "IE - Incrementar Estoque" << std::endl << "DE - Decrementar Estoque" << std::endl;
                std::cin >> CPFr;
                CPFr = padroniza_entrada(CPFr);
                try{
                    if(CPFr != "IE" && CPFr != "DE" && CPFr != "LE"){
                        throw std::invalid_argument("Entrada invalida - digite novamente");
                    }
                }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarOE(CPFr);
                
                }
                if(CPFr == "LE"){
                    sistema.ListarEstoque();
                }

                else if(CPFr == "IE"){
                    std::cout << "Qual filme deseja incrimentar ? [cod]" << std::endl;
                    std::cin >> cod;
                    try{
                        if(cod < 0 || cod > 10000){
                            throw std::invalid_argument("Quantidade tem que ser maior que 0 e menor que 10000- Digite novamente");
                        }
                        else if(!sistema.ExisteFilme(cod)){

                            throw std::invalid_argument("Filme inexistente- Digite novamente");
                        }
                    }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarCodN(cod);
                    }

                    std::cout << "Quantos ?" << std::endl;
                    std::cin >> quantidade;

                    try{
                        if(quantidade < 0){
                            throw std::invalid_argument("Os dias tem que ser maior que 0 - Digite novamente");
                        }
                    }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarQuantidade(cod);
                    }

                    sistema.incrementarEstoque(cod,quantidade);
    
                }
                else if(CPFr == "DE"){
                    std::cout << "Qual filme deseja decrementar ? [cod]" << std::endl;
                    std::cin >> cod;
                        try{
                        if(cod < 0 || cod > 10000){
                            throw std::invalid_argument("Quantidade tem que ser maior que 0 e menor que 10000- Digite novamente");
                        }
                        else if(!sistema.ExisteFilme(cod)){

                            throw std::invalid_argument("Filme inexistente- Digite novamente");
                        }
                    }catch(std::invalid_argument &e){
                            std::cout << e.what() << std::endl;
                            sistema.TratarCodN(cod);
                    }
                    std::cout << "Quantos ?" << std::endl;
                    std::cin >> quantidade;

                    try{
                        if(quantidade < 0){
                            throw std::invalid_argument("Os dias tem que ser maior que 0 - Digite novamente");
                        }
                    }catch(std::invalid_argument &e){
                        std::cout << e.what() << std::endl;
                        sistema.TratarQuantidade(cod);
                    }

                    sistema.decrementarEstoque(cod,quantidade);

                }

            }else{
                throw std::invalid_argument("Entrada invalida - Digite novamente");
            }

            

        } catch(const std::invalid_argument &e){
            std::cout << e.what() << std::endl;
        }
    }
}
