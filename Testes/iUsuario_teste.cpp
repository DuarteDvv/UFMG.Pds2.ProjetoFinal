#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Usuario.hpp"
#include "Film.hpp" //Biblioteca incluída para teste da função addCarrinho e ListarCarrinho
#include <sstream>

TEST_CASE("Obter CPF do usuário")
{
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf); 
        
        CHECK(u->getCPF() == "00100100101");
}

TEST_CASE("Obter Nome do usuário")
{
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf);

        CHECK(u->getNome()=="Ludovicus");
}

TEST_CASE("Obter e incrementar número de acessos do usuário")
{       
        /* --------------------------------------------------------
        Este TEST_CASE verifica os métodos getAcessos e AcessAdd
        ao mesmo tempo
        -------------------------------------------------------- */
        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
        Usuario* u = new Usuario(nome, cpf);

        CHECK(u->getAcessos()==1);
        u->AcessAdd(25); 
        CHECK(u->getAcessos()==26);
}

TEST_CASE("Adicionar filme no carrinho e listar Carrinho")
{
        dvd* e = new dvd(456,"Título teste II",1,"promocao");

        std::string nome = "Ludovicus";
        std::string cpf = "00100100101";
      
        Usuario u(nome, cpf);
        u.addCarrinho(e);
        std::stringstream buffer;
        std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

        u.ListarCarrinho();

        std::cout.rdbuf(old);
        std::string saida = buffer.str();
        CHECK(saida == "456 Título teste II DVD\n");

}





