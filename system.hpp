#ifndef _sys
#define _sys

#include <list>
#include <iostream>
#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"

class Sistema{
    private:
        std::list<Usuario*> Usuarios;
        std::list<filme*> Catalogo;


    public:
        bool VerificarCpf(std::string &);
        bool VerificarNome(std::string &);
        bool ExisteUsuario(std::string &);
        void CadastrarCliente(Usuario* &);
        void RemoverCliente(std::string &);
        void ListarCliente(std::string &);


        void CadastrarFilme(dvd* &);
        void CadastrarFilme(fita* &);
        bool ExisteFilme(int &);
        void ListarFilmes(std::string &);
        void RemoverFilme(int &);


        


};


#endif