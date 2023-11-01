#include <iostream> 
#include <cctype> 

//essa função verifica se o nome do usuário é escrito com letras comuns, se sim, retorna true, se tiver número ou caractere especial, retorna false


bool verifica_nome(const std::string &nome){
    for(char a : nome){
        if(!isalpha(a) && !isspace(a)){
            return false;
        }
    } 
    return true;
} 

//Função para verificar se um usuário já está registrado na lista de usuários
bool existeUsuario(const std::list<Usuario>& Banco_de_usuarios, const std::string& nome, const std::string& cpf){
    for(const Usuario& usuario : Banco_de_usuarios){
        if(usuario.nome == nome && usuario.cpf==cpf)
        {
            return true;
        }

    }
    return false;
}
