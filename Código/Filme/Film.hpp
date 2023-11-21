#ifndef _FILM
#define _FILM
#include <iostream>
#include <string>

class filme{
    private:
        int codigo;
        std::string titulo;
        int quantidade;

    public:
        filme(int cod, std::string tit, int quant) : codigo(cod), titulo(tit), quantidade(quant){} 
        virtual ~filme() = default;

        void MaisUm(); //adiciona uma unidade do filme
        void MenosUm(); //reduz uma unidade do filme
        int getCod();
        std::string getTitulo();
        int getQuantidade();
        virtual std::string getTipo() = 0;
        virtual float CalcularPreco(int) = 0;
        void addQuantidade(int &);
        void reduzirQuantidade(int &);
  
};
class fita : public filme{
    private:
        bool rebobinado;

    public:
        fita(int cod, std::string tit, int quant) : filme(cod,tit,quant){}
        ~fita() = default;

        std::string getTipo() override{
            return "FITA";
        }

        float CalcularPreco(int) override;

        
        bool isRebobinado();
};

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

        
        bool isPromo();
        bool isEstoque();
        bool isLanca();
};

#endif
