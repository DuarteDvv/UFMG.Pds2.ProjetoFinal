#include "Usuario.hpp"
#include <list>
#include <iostream> 
#include <cctype>  
#include <string>

//Essa função verifica se o nome do usuário é escrito com letras comuns, se sim, retorna true, se tiver número ou caractere especial, retorna false
bool verifica_nome(const std::string &nome){
    for(char a : nome){
        if(!isalpha(a) && !isspace(a)){
            return false;
        }
    } 
    return true;
} 

//Função para verificar se um usuário já está registrado na lista de usuários
bool existeUsuario(const std::list<Usuario>& Banco_de_usuarios, const std::string& cpf){
    for(Usuario usuario : Banco_de_usuarios){
        if(usuario.getCPF() == cpf)
        {
            return true;
        }

    }
    return false;
}
 

 //Função que vai verificar se o cpf é válido 
bool verifica_cpf(const std::string &cpf){ 
    for(char a : cpf){
        if(!std::isdigit(a)){
            return false;
            break;
        }
    } 
    if(cpf.length()!=11){
        return false;
    }
    
    return true;
}
    
