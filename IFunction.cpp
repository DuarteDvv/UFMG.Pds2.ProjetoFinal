#include "functions.hpp"
#include <iostream> 
#include <string>



bool verifica_nome(std::string &nome){
    for(char a : nome){
        if(!isalpha(a) && !isspace(a)){
            return false;
        }
    } 
    return true;
} 

//Função para verificar se um usuário já está registrado na lista de usuários
bool existeUsuario( std::list<Usuario>& Banco_de_usuarios,  const std::string &cpf) {
    for ( auto it = Banco_de_usuarios.begin(); it != Banco_de_usuarios.end() ;++it ) {
        if (it->getCPF() == cpf) {
            return true; 
        } 
    }
    return false;
}

 

 //Função que vai verificar se o cpf é válido 
bool verifica_cpf(std::string &cpf){
    for(char a : cpf){
        if(!std::isdigit(a)){
            return false;
            break;
        }
    } 
    if(cpf.length() != 11){
        return false;
    }
    
    return true;
}
// Função que remove um usuario da lista
void removeUsuario( std::list<Usuario> &Banco_de_usuarios, const std::string &cpf) {
    for (auto it = Banco_de_usuarios.begin(); it != Banco_de_usuarios.end();++it ) {
        if (it->getCPF() == (cpf)) {
            it = Banco_de_usuarios.erase(it); 
        } 
    }
}

// Funçoes que definem o parametro para ordenar em ordem crescente caso cpf ou alfabetica caso nome;
// Poderia ter utilizado funções lambdas -> [](const std::string& a, const std::string& b) {return a < b;}
bool compN( Usuario &a, Usuario &b){
    return a.getNome() < b.getNome(); 
}
bool compC( Usuario& a,  Usuario& b){
    return std::stoll(a.getCPF())  < std::stoll(b.getCPF());
}

