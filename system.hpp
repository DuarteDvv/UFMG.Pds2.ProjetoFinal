#ifndef _sys
#define _sys

#include <list>
#include <iostream>
#include "Usuario.hpp"
#include "Film.hpp"
#include "functions.hpp"
#include <fstream>

class Sistema{
    private:
        std::list<Usuario*> Usuarios;
        std::list<filme*> Catalogo;


    public:
        //User Methods
        bool VerificarCpf(std::string &);
        bool VerificarNome(std::string &);
        bool ExisteUsuario(std::string &);
        void CadastrarCliente(Usuario* &);
        void RemoverCliente(std::string &);
        void ListarCliente(std::string &);

        //Film Methods
        void CadastrarFilme(filme* &);
        bool ExisteFilme(int &);
        void ListarFilmes(std::string &);
        void RemoverFilme(int &);
        void AdicionarCarrinho(int &, std::string&);
        void ListarCompras(std::string &);
        void Recibo(std::string &, int &);
        void CadastrarFilmesDoArquivo(std::ifstream &);

        


};


#endif