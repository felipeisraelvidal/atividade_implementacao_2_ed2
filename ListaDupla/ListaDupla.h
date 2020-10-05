#include "NoDuplo/NoDuplo.h"

class ListaDupla {
  public:
    ListaDupla();
    NoDuplo* busca(int val);
    NoDuplo* insereInicio(int val);
    void removeInicio();
    NoDuplo* insereFinal(int val);
    void removeFinal();
    int getFirst();
    int getLast();
    int getCount();
    void print();
    void destroy();

  private:
    NoDuplo *primeiro;
    int n;
    NoDuplo *ultimo;
};