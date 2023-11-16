#include "system.hpp"

void Sistema::CadastrarCliente(Usuario* &user){

    this->Usuarios.push_back(user);
}

void Sistema::RemoverCliente(std::string &cpf){
    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    { 
        if ((*it)->getCPF() == cpf)
        {   
            delete (*it);
            this->Usuarios.erase(it);   
            break;
        }
    }
}

void Sistema::ListarCliente(std::string &cat){
    if (cat == "N")
    {
        this->Usuarios.sort(compN);
    }
    else if (cat == "C")
    {
        this->Usuarios.sort(compC);
    }

    for (Usuario* n : this->Usuarios)
    {
        std::cout << "|| " << (*n).getCPF() << " || "<< ">> " << (*n).getNome() << std::endl;
    }
}

bool Sistema::VerificarCpf(std::string &cpf){
    for (char a : cpf)
    {
        if (!std::isdigit(a))
        {
            std::cout << "ERRO: dados incorretos" << std::endl;
            return false;
        }
    }
    if (cpf.length() != 11)
    {
        std::cout << "ERRO: dados incorretos" << std::endl;
        return false;
        
    }

    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if ((*it)->getCPF() == cpf)
        {   
            std::cout << "ERRO: CPF repetido" << std::endl;
            return false;
        }
    }

    return true;
}


bool Sistema::VerificarNome(std::string &nome){
    for (char a : nome)
    {
        if (!isalpha(a) && !isspace(a))
        {
            std::cout << "ERRO: dados incorretos" << std::endl;
            return false;
        }
    }
    return true;
    
}

bool Sistema::ExisteUsuario(std::string &cpf){
    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if ((*it)->getCPF() == cpf)
        {   
            return true;
        }
    }
    return false;
}

void Sistema::CadastrarFilme(filme* &a){
    this->Catalogo.push_back(a);
}

 
bool Sistema::ExisteFilme(int &cod){
    for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it)
    {
        if ((*it)->getCod() == cod)
        {   
            return true;
        }
    }
    return false;
}

void Sistema::ListarFilmes(std::string &cat){
    if (cat == "T")
    {
        this->Catalogo.sort(compT);
    }
    else if (cat == "C")
    {
        this->Catalogo.sort(compCf);
    }

    for (filme* n : this->Catalogo)
    {
        std::cout << "||" << (*n).getCod() << "|| "<< ">> " << (*n).getTitulo() << std::endl;
    }
}

 void Sistema::RemoverFilme(int &cod){
    for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it)
    {
        if ((*it)->getCod() == cod)
        {   
            delete (*it);
            this->Catalogo.erase(it);   
            break;
        }
    }

 }

 void Sistema::AdicionarCarrinho(int &cod, std::string &cpf){
    for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it)
    {
        if ((*it)->getCod() == cod)
        {
            if((*it)->getQuantidade() != 0){
                (*it)->MenosUm();
                for (auto U = this->Usuarios.begin(); U != this->Usuarios.end(); ++U){
                    if((*U)->getCPF() == cpf){
                        (*U)->addCarrinho(*it);
                    }

                }
            }
            else{
                std::cout << "ERRO: Filme esgotado" << std::endl;
            }
                       
        }
    }
 }

 void Sistema::ListarCompras(std::string &cpf){
    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if ((*it)->getCPF() == cpf)
        {   
            std::cout << "Cliente " << (*it)->getCPF() << " " << (*it)->getNome() << " alugou os filmes:" << std::endl;
           (*it)->ListarCarrinho();
        }    
    }
}

void Sistema::Recibo(std::string &cpf, int& dias ){
    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if ((*it)->getCPF() == cpf)
        {     
            std::cout << "Cliente " << (*it)->getCPF() << " " << (*it)->getNome() << " devolveu os filmes:" << std::endl;
           (*it)->recibo(dias);
        }    
    }

}

void Sistema::CadastrarFilmesDoArquivo(std::ifstream & file){

    std::string tipo, titulo, categoria, tituloComCategoria;
    int quantidade, codigo;
    int N = 0;

    while (file >> tipo >> quantidade >> codigo) {
        N++;

        file.ignore();  

        if (tipo == "D") {
            getline(file,tituloComCategoria);
            int posicao = tituloComCategoria.find_last_of(' ');
            titulo = tituloComCategoria.substr(0,posicao);
            categoria = tituloComCategoria.substr(posicao + 1);

            filme* d = new dvd(codigo,titulo,quantidade,categoria); 
            Catalogo.push_back(d);
        } else {
            getline(file, titulo);
            filme* fit = new fita(codigo,titulo,quantidade);
            Catalogo.push_back(fit);
        }
    }

    file.close();
    std::cout << N << "Filmes cadastrados com sucessso" << std::endl;
}
 


//extra

void Sistema::LoadData(){
    int acessos;
    std::string nome, cpf;

    std::ifstream Data("Data.txt");
    if(Data.is_open()){
        while(Data >> acessos >> cpf ){
            Data.ignore();

            std::getline(Data, nome);
            Usuario* U = new Usuario(nome,cpf);
            U->AcessAdd(acessos);
            Usuarios.push_back(U);
        }

    }
    else {
            std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }

}

void Sistema::SaveData(){
    std::ofstream Data("Data.txt");
    if (Data.is_open()) {
            for(auto it = Usuarios.begin(); it != Usuarios.end(); ++it){
                Data << (*it)->getAcessos() << " " << (*it)->getCPF() << " " << (*it)->getNome() << "\n";
            }
            Data.close();
            
        } 
        else {
            std::cerr << "Erro ao abrir o arquivo para escrita.\n";
    }
}

void Sistema::AnimCarregarDados(){

        const int totalProgresso = 100;
        const int duracaoCarregamento = 50;  
        const int sleepDuration = 50;       

        LimparTela();

        for (int progresso = 0; progresso <= totalProgresso; ++progresso) {
            Desenha(progresso, totalProgresso);
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepDuration));
        }

        LimparTela();

        std::cout << "\033[1;32mDados Carregados!\033[0m\n";
        
}

void Sistema::AnimacaoEscolha(){
    for (int i = 0; i < 18; ++i) {
            switch (i % 4) {
                case 0:
                    std::cout << "\r|";
                    break;
                case 1:
                    std::cout << "\r/";
                    break;
                case 2:
                    std::cout << "\r-";
                    break;
                case 3:
                    std::cout << "\r\\";
                    break;
            }
            std::cout.flush();
            std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }
}


void Sistema::animacaoSalvando() {
    const int duracaoAnimacao = 10; 
    const int duracaoPonto = 500;   

    for (int i = 0; i < duracaoAnimacao; ++i) {
        LimparTela();
        std::cout << "Salvando";
        for (int j = 0; j < i % 4; ++j) {
            std::cout << ".";
        }
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(duracaoPonto));
    }

    LimparTela();

    std::cout << "\033[1;32mDados salvos com sucesso!\033[0m\n" << std::endl <<"Volte sempre!";
}

    
