#include "system.hpp"
#include <cassert>

void Sistema::TratarCPF(std::string &cpf){
    std::cin >> cpf;
    LimparTela();
    
    while(!this->VerificarCpf(cpf)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> cpf;
        LimparTela();
    }
}

void Sistema::TratarNome( std::string &nome){
    std::cin >> nome;
    LimparTela();

    while(!this->VerificarNome(nome)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> nome;
        LimparTela();
    }
}

void Sistema::TratarExistenciaU(std::string &CPFr){
    std::cin >> CPFr;
    LimparTela();

    while(this->ExisteUsuario(CPFr)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> CPFr;
        LimparTela();
    }

}

void Sistema::TratarListagemU(std::string &U){
    std::cin >> U;
    LimparTela();

    while(U != "C" && U != "N"){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> U;
        LimparTela();
    }

}

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
            std::cout << "ERRO: Apenas numeros sao permitidos" << std::endl;
            return false;
        }
    }
    if (cpf.length() != 11)
    {
        std::cout << "ERRO: CPF possui 11 digitos" << std::endl;
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
            std::cout << "ERRO: Apenas letras e espacos" << std::endl;
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

void Sistema::TratarListagemF(std::string &F){
    std::cin >> F;
    LimparTela();

    while(F != "C" && F != "N"){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> F;
        LimparTela();
    }

}

void Sistema::TratarExistenciaF(int & cod){
    std::cin >> cod;
    LimparTela();

    while(!this->ExisteFilme(cod)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> cod;
        LimparTela();
    }
}

void Sistema::TratarCat(std::string &cat){
    std::cin >> cat;
    LimparTela();

    while(!verifica_categoria(cat)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> cat;
        LimparTela();
    }
}

void Sistema::TratarQuantidade(int &q){
    std::cin >> q;
    LimparTela();

    while(q < 0){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> q;
        LimparTela();
    }

}

void Sistema::TratarCod(int &c){
    std::cin >> c;
    LimparTela();

    while(c < 0 || c > 10000 || this->ExisteFilme(c)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> c;
        LimparTela();
    }
}

void Sistema::TratarCodN(int &c){
    std::cin >> c;
    LimparTela();

    while(c < 0 || c > 10000 || !this->ExisteFilme(c)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> c;
        LimparTela();
    }
}


void Sistema::TratarTIPO(std::string & tipo){
    std::cin >> tipo;
    LimparTela();

    while(tipo != "D" && tipo != "F"){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> tipo;
        LimparTela();
    }
}

bool Sistema::VerificaTitulo(std::string &tit){
    for (char a : tit)
    {
        if (!isalnum(a) && !isspace(a))
        {
           return false;
        }
    }
    return true;
}

void Sistema::TratarTitulo(std::string &tit){
    std::cin >> tit;
    LimparTela();

    while(!VerificaTitulo(tit)){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> tit;
        LimparTela();
    }
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


void Sistema::TratarSenha(std::string &sen){
    std::cin >> sen;
    LimparTela();

    while(sen.length() != 4){
        std::cout << "Digite o padrão correto" << std::endl;
        std::cin >> sen;
        LimparTela();
    }
}

void Sistema::LoadData(){
    int acessos;
    std::string nome, cpf;

    std::ifstream Data("Data.txt");

    assert(Data.is_open() && "ERRO na abertura do aquivo de leitura");
    
    while(Data >> acessos >> cpf ){
        Data.ignore();

        std::getline(Data, nome);
        Usuario* U = new Usuario(nome,cpf);
        U->AcessAdd(acessos);
        Usuarios.push_back(U);
    }
}

void Sistema::SaveData(){
    std::ofstream Data("Data.txt");

    assert(Data.is_open() && "ERRO na abertura do aquivo de escrita");

    for(auto it = Usuarios.begin(); it != Usuarios.end(); ++it){
        Data << (*it)->getAcessos() << " " << (*it)->getCPF() << " " << (*it)->getNome() << "\n";
    }
    Data.close();       
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

void Sistema::ListarEstoque(){
    if(this->Catalogo.size() != 0){
        for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it){
            std::cout << (*it)->getTipo() << " " << (*it)->getTitulo() << " Copias: " << (*it)->getQuantidade() << std::endl; 

        }
    }
    else{
        std::cout << "Estoque vazio" << std::endl;
    }   
}

void Sistema::RegistroDeAlugays(){
    for(auto it = Usuarios.begin(); it != Usuarios.end(); ++it){
        std::cout << "O usuario "<< (*it)->getNome() << "tem alugado os filmes:" << std::endl;
        (*it)->ListarCarrinho();
        std::cout << "----------------------------------------------------------------------" << std::endl;
    }

}

void Sistema::incrementarEstoque(int & cod, int &q){
    for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it)
    {
        if ((*it)->getCod() == cod){
            (*it)->addQuantidade(q);


        }
    }
}

void Sistema::decrementarEstoque(int & cod, int &q){
    for (auto it = this->Catalogo.begin(); it != this->Catalogo.end(); ++it)
    {
        if ((*it)->getCod() == cod){
            (*it)->reduzirQuantidade(q);
        }
    }
}

void Sistema::TratarOE(std::string & o){
    std::cin >> o;
    LimparTela();

    while(o != "IE" && o != "DE" && o != "LE"){
        std::cout << "Digite um valido" << std::endl;
        std::cin >> o;
        LimparTela();
    }

}

void Sistema::SugerirFilme() 
{
    std::string nomeFilme;
    std::cout<< "\nNão encontrou o filme que queria?\n";
    std::cout<< "Indique um novo filme para nossa locadora ou digite C para continuar!\n";
    std::cout<< "(Para indicar o filme basta digitar o titulo)\n";
    
    std::cin>>nomeFilme;
    
    
    if(nomeFilme!="C")
    {
        // Abre o arquivo para escrita, em modo de adição ao final do arquivo
        std::ofstream arquivoSugestoes("SugestaoDosUsuarios.txt", std::ios::app);
    
        // Verifica se o arquivo foi aberto com sucesso
        if (arquivoSugestoes.is_open()) 
        {
        // Escreve a sugestão no arquivo
        arquivoSugestoes << nomeFilme << std::endl;
        std::cout << "Sugestão registrada com sucesso!\n";
        std::cout<< "Agradecemos sua contribuicao! ;)";
        // Fecha o arquivo
        arquivoSugestoes.close();
        
        std::cout <<"\n";
        bool finalizar_porgrama = finalizar_prog();
        if(finalizar_porgrama)
        {
            cmd = "FS";
            break;
            
        }
        else 
        {
            mostrarOpcoes();
        }
        
        } 
    
        else 
        {
        std::cerr << "Erro ao abrir o arquivo.\n";
        bool finalizar_porgrama = finalizar_prog();
        if(finalizar_porgrama)
        {
            cmd = "FS";
            break;
            
        }
        else 
        {
            mostrarOpcoes();
        }
        }
    
    }
    else
    {
        std::cout <<"\n";
        bool finalizar_porgrama = finalizar_prog();
        if(finalizar_porgrama)
        {
            cmd = "FS";
            break;
            
        }
        else 
        {
            mostrarOpcoes();
        }
    }
    
}


    
