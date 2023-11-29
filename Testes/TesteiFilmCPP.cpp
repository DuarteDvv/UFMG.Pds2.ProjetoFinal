#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "system.hpp"

// g++ iFilm.o IFunction.o isystem.o iUsuario.o TesteiFilmCPP.cpp -o

TEST_CASE("Cálculo de Preço para diferentes tipos de filme")
{

    /* -------------------------------------------------------------------
        Adendo: A hipótese em que a quantidade de dias inserida é negativa
        não foi inserida neste escopo pois essa exceção é tratada ainda
        na função main.    
    ---------------------------------------------------------------------- */

    SUBCASE("Tipo Estoque") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0 * 5));
    }

     SUBCASE("Tipo Promocao") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0));
    }

    SUBCASE("Tipo Lançamento") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "lancamento";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(100.0));
    }

    SUBCASE("Tipo Não Especificado") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "qualquer";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == doctest::Approx(0.0));
    }

/*

    ---------------- ALTERAR ------------------
    SUBCASE("Tipo Fita") 
    {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        filme* d = new fita(123,TituloTeste,1); 
        sistema.CadastrarFilme(d);

        CHECK(d->CalcularPreco(5) == 5.0);
    }
    */

}

/*

---------------- ALTERAR ------------------

TEST_CASE("Fita rebobinada ou não") {
        Sistema sistema;
        std::string TituloTeste = "Título teste";
        filme* d = new fita(123,TituloTeste,1); 
        sistema.CadastrarFilme(d);

        CHECK(d->isRebobinado == false) ;

}
*/

TEST_CASE("Incrementar quantidade do filme e obter quantidade")
{
    Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);
        
        d->MaisUm();
        CHECK(d->getQuantidade()==2);
        d->MaisUm();
        CHECK(d->getQuantidade()==3);

}

TEST_CASE("Decrementar quantidade do filme e obter quantidade")
{
    /* -------------------------------------------------------------------
        Adendo: A hipótese em que a quantidade de filmes é igual 0 e mesmo
        assim é decrementada não foi incluída nos testes pois foi tratada
        como exceção no arquivo isystem.cpp
    ---------------------------------------------------------------------- */

    Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);
        
        d->MenosUm();
        CHECK(d->getQuantidade()==0);
}

TEST_CASE("Obter Código do filme")
{
    Sistema sistema;
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        sistema.CadastrarFilme(d);

        CHECK(d->getCod()==123);        
}





