#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Film.hpp"


TEST_CASE("Cálculo de Preço para diferentes tipos de filme")
{

    /* -------------------------------------------------------------------
        Adendo: A hipótese em que a quantidade de dias inserida é negativa
        não foi inserida neste escopo pois essa exceção é tratada ainda
        na função main.    
    ---------------------------------------------------------------------- */

    SUBCASE("Tipo Estoque") 
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        
        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0 * 5));
    }

     SUBCASE("Tipo Promocao") 
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 

        CHECK(d->CalcularPreco(5) == doctest::Approx(10.0));
    }

    SUBCASE("Tipo Lançamento") 
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "lancamento";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 

        CHECK(d->CalcularPreco(5) == doctest::Approx(100.0));
    }

    SUBCASE("Tipo Não Especificado") 
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "qualquer";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 

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
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        
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

        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 
        
        d->MenosUm();
        CHECK(d->getQuantidade()==0);
}

TEST_CASE("Obter Código do filme")
{
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 

        CHECK(d->getCod()==123);        
}

TEST_CASE("Obter Título do filme")
{
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "promocao";
        filme* d = new dvd(123,TituloTeste,1,TipoTeste); 

        CHECK(d->getTitulo()=="Título teste");
}

TEST_CASE("Verifica tipo")
{
    SUBCASE("É estoque?")
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        dvd* d = new dvd(123,TituloTeste,1,TipoTeste);
        dvd* e = new dvd(456,"Título teste II",1,"promocao"); 

        CHECK(d->isEstoque()==true);
        CHECK(e->isEstoque()==false);

    }

    SUBCASE("É promoção?")
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        dvd* d = new dvd(123,TituloTeste,1,TipoTeste);
        dvd* e = new dvd(456,"Título teste II",1,"promocao");

        CHECK(e->isPromo()==true);
        CHECK(d->isPromo()==false);

    }

    SUBCASE("É lançamento?")
    {
        std::string TituloTeste = "Título teste";
        std::string TipoTeste = "lancamento";
        dvd* d = new dvd(123,TituloTeste,1,TipoTeste);
        dvd* e = new dvd(456,"Título teste II",1,"promocao");

        CHECK(d->isLanca()==true);
        CHECK(e->isLanca()==false);

    }

}

TEST_CASE("Incrementar quantidade do filme (com parâmetro)")
{
   std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        dvd* d = new dvd(123,TituloTeste,1,TipoTeste);
        int a =27;
        d->addQuantidade(a);
        
        CHECK(d->getQuantidade()==28);
}

TEST_CASE("Decrementar quantidade do filme (com parâmetro)")
{
   std::string TituloTeste = "Título teste";
        std::string TipoTeste = "estoque";
        dvd* d = new dvd(123,TituloTeste,12,TipoTeste);
        int a =10;
        d->reduzirQuantidade(a);
        
        CHECK(d->getQuantidade()==2);
}




