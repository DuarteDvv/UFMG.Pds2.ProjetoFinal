#ifndef _FILM
#define _FILM
#include <iostream>
#include <string>

// Uma das classes principais em todo o sistema, classe pai 
class filme{
    private:
        int codigo;
        std::string titulo;
        int quantidade;

    public:
        filme(int cod, std::string tit, int quant) : codigo(cod), titulo(tit), quantidade(quant){} 
        virtual ~filme() = default;

        void MaisUm(); // Adiciona uma unidade do filme
        void MenosUm(); // Eeduz uma unidade do filme

        // Métodos de acesso aos membros privados da classe.
        int getCod();
        std::string getTitulo();
        int getQuantidade();

        // Métodos virtuais puros que serão implementados nas classes derivadas
        virtual std::string getTipo() = 0; // Retorna o tipo do filme
        virtual float CalcularPreco(int) = 0; // Calcula o preço do filme com base em um parâmetro
        
        // Métodos para manipulação da quantidade de filmes
        void addQuantidade(int &);
        void reduzirQuantidade(int &);
  
}; 

// Classe derivada de "filme" 
class fita : public filme{
    private:
        bool rebobinado;

    public: 
    // Construtor que inicializa os membros da classe base e já determina o tipo do DVD
        fita(int cod, std::string tit, int quant) : filme(cod,tit,quant){}
        ~fita() = default;

        std::string getTipo() override{
            return "FITA";
        }

        float CalcularPreco(int) override;

        // Método para verificar se a fita está rebobinada
        bool isRebobinado();
};

// Classe derivada de "filme"
class dvd : public filme{
    private:
        bool promocao = false;

        bool estoque = false;
        bool lancamento = false;
    public:
        dvd(int cod, std::string tit, int quant, std::string tipo) : filme(cod,tit,quant){
            if(tipo == "promocao")
                promocao = true;
            else if(tipo == "estoque")
                estoque = true;
            else if(tipo == "lancamento")
                lancamento = true;
        }
        ~dvd() = default;

        std::string getTipo() override{
            return "DVD";
        }

        float CalcularPreco(int) override;

        // Métodos para verificar o tipo do DVD
        bool isPromo();
        bool isEstoque();
        bool isLanca();
};

#endif
