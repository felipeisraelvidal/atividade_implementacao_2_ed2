#include "../ListaDupla/ListaDupla.h"

enum FuncaoHash {
  DIVISAO,
  MULTIPLICACAO,
  MINHAHASH
};

class TabelaHash { 

  private:
    ListaDupla* *table;
    int tam;
    int colisoes;
    FuncaoHash hash;
      
    int hashDivisao(int chave);
    int hashMultiplicacao(int chave);
    int minhaHash(int chave);

  public:
    void create(int m, FuncaoHash hash); // Cria um tabela (array) de tamanho m
    void destroy();
    
    NoDuplo* insert(int key, int data);
    NoDuplo* lookup(int key, int data);
    
    void print();
    
    int getItem(int index);
    void setItem(int index, int value);

    int getColisoes();
};