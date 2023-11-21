#ifndef _sys
#define _sys

#include <list>
#include <iostream>
#include "Usuario.hpp"
#include "Film.hpp"
#include "Function.hpp"
#include <fstream>
#include <thread>
#include <chrono>

class Sistema
{
private:
    std::list<Usuario *> Usuarios;
    std::list<filme *> Catalogo;

public:
    ~Sistema()
    {
        for (auto &usuarioPtr : Usuarios)
        {
            delete usuarioPtr;
        }

        for (auto &filmePtr : Catalogo)
        {
            delete filmePtr;
        }
    }

    // User Methods
    void TratarCPF(std::string &);
    void TratarNome(std::string &);
    void TratarExistenciaU(std::string &);
    void TratarListagemU(std::string &);
    bool VerificarCpf(std::string &);
    bool VerificarNome(std::string &);
    bool ExisteUsuario(std::string &);
    void CadastrarCliente(Usuario *&);
    void RemoverCliente(std::string &);
    void ListarCliente(std::string &);
    void SugerirFilme();

    // Film Methods
    void TratarTIPO(std::string &);
    void TratarQuantidade(int &);
    void TratarCod(int &);
    void TratarTitulo(std::string &);
    void CadastrarFilme(filme *&);
    bool VerificaTitulo(std::string &);
    void TratarCat(std::string &);
    void TratarCodN(int &);
    void TratarListagemF(std::string &);
    void TratarExistenciaF(int &);
    bool ExisteFilme(int &);
    void ListarFilmes(std::string &);
    void RemoverFilme(int &);
    void AdicionarCarrinho(int &, std::string &);
    void ListarCompras(std::string &);
    void Recibo(std::string &, int &);
    void CadastrarFilmesDoArquivo(std::ifstream &);

    // Extra
    void TratarOE(std::string &);
    void TratarSenha(std::string &);
    void AnimCarregarDados();
    void animacaoSalvando();
    void AnimacaoEscolha();
    void LoadData();
    void SaveData();
    void ListarEstoque();
    void RegistroDeAlugays();
    void incrementarEstoque(int &, int &);
    void decrementarEstoque(int &, int &);
};

#endif
