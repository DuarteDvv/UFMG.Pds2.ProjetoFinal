#include "system.hpp"

void Sistema::CadastrarCliente(Usuario* &user){

    this->Usuarios.push_back(user);
}

void Sistema::RemoverCliente(std::string &cpf){
    for (auto it = this->Usuarios.begin(); it != this->Usuarios.end(); ++it)
    {
        if ((*it)->getCPF() == cpf)
        {
            this->Usuarios.erase(it);   
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
        std::cout << "||" << (*n).getCPF() << "|| "<< ">> " << (*n).getNome() << std::endl;
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

void Sistema::CadastrarFilme(dvd* &film){
    this->Catalogo.push_back(film);
}
void Sistema::CadastrarFilme(fita* &film){
    this->Catalogo.push_back(film);
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
            this->Catalogo.erase(it);   
        }
    }

 }