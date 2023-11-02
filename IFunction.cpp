#include "functions.h"

bool verifica_nome(std::string &nome){
    for(char a : nome){
        if(!isalpha(a) && !isspace(a)){
            return false;
        }
    } 
    return true;
} 

//Função para verificar se um usuário já está registrado na lista de usuários
bool existeUsuario( std::list<Usuario>& Banco_de_usuarios,std::string& cpf){
    for(Usuario usuario : Banco_de_usuarios){
        if(usuario.getCPF() == cpf)
        {
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
/* void removeUsuario(std::list<Usuario> &Banco_de_usuarios, std::string &cpf){
    for(Usuario usuario : Banco_de_usuarios){
        if(usuario.getCPF() == cpf)
        {
            Banco_de_usuarios.remove(usuario);
        }

    }
}*/

// Função que ordena em ordem crescente caso cpf ou alfabetica caso nome;
/*void ordenar(std::list<Usuario> &Banco, std::string &tipo){
    if(tipo == "N"){
         std::sort(Banco.begin(), Banco.end(),[]( Usuario &a, Usuario &b){return a.getNome() < b.getNome();}); 
         
    }
    else if(tipo == "C"){
        std::sort(Banco.begin(), Banco.end(),[]( Usuario &a, Usuario &b){return a.getCPF() < b.getCPF();}); 
    }
}*/