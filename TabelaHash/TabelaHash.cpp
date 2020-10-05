#include <iostream>
#include <cmath>
#include "TabelaHash.h"

using namespace std;

void TabelaHash::create(int m, FuncaoHash hash) {
  if (m > 0) {
    this->colisoes = 0;
    this->tam = m;
    this->hash = hash;
    this->table = (ListaDupla**)malloc(this->tam * sizeof(ListaDupla));
    for (int i = 0; i < this->tam; i++) {
      // Iniciar cada posicao da tabela com NULL
      this->table[i] = NULL;
    }
  } else {
    exit(0);
  }
}

int TabelaHash::hashDivisao(int chave) {
  return chave % this->tam;
}

int TabelaHash::hashMultiplicacao(int chave) {
  float k = chave;
  float a = ((sqrt(5) - 1) / 2);
  float ka = k * a;
  float c = fmod(ka, 1.0);
  int hk = floor(this->tam * c);
  return hk;
}

int TabelaHash::minhaHash(int chave) {
  // Converter a chave para a base 8
  int octalNumber = 0;
  int i = 1;
  int decimalNumber = chave;

  while (decimalNumber != 0) {
    octalNumber += (decimalNumber % 8) * i;
    decimalNumber /= 8;
    i *= 10;
  }
  
  return hashDivisao(octalNumber);
}

NoDuplo* TabelaHash::insert(int key, int data) {
  NoDuplo *p = lookup(key, data);
  if (p == NULL) {
    
    int tableIndex;
    switch (hash) {
      case DIVISAO: {
        tableIndex = hashDivisao(key);
        break;
      }
      case MULTIPLICACAO: {
        tableIndex = hashMultiplicacao(key);
        break;
      }
      case MINHAHASH: {
        tableIndex = minhaHash(key);
        break;
      }
      default:
        break;
    }
    
    if (this->table[tableIndex] == NULL) {
      ListaDupla* newList = new ListaDupla();
      p = newList->insereInicio(data);
      this->table[tableIndex] = newList;
    } else {
      p = this->table[tableIndex]->insereFinal(data);
      this->colisoes += 1;
    }
  }
  
  return p;
}

void TabelaHash::print() {
  for (int i = 0; i < this->tam; i++) {
    cout << i << ": ";
    if (this->table[i] != NULL) {
      this->table[i]->print();
    } else {
      cout << "NULL" << endl;
    }
  }
}

int TabelaHash::getColisoes() {
  return colisoes;
}

NoDuplo* TabelaHash::lookup(int key, int data) {
  int tableIndex;
  switch (hash) {
    case DIVISAO: {
      tableIndex = hashDivisao(key);
      break;
    }
    case MULTIPLICACAO: {
      tableIndex = hashMultiplicacao(key);
      break;
    }
    case MINHAHASH: {
      tableIndex = minhaHash(key);
      break;
    }
    default:
      break;
  }
  if (table[tableIndex] != NULL) {
    NoDuplo* p = table[tableIndex]->busca(data);
    return p;
  } else {
    return NULL;
  }
}

void TabelaHash::destroy() {
  for (int i = 0; i < tam; i++) {
    if (this->table[i] != NULL) {
      this->table[i]->destroy();
    }
  }
  delete table;
}
