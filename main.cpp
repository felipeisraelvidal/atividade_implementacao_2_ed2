#include <iostream>
#include "TabelaHash/TabelaHash.h"

using namespace std;

int* randomArray(int m) {
  int* array = (int*)malloc(m * sizeof(int));
  srand((unsigned) time(0));
  for (int i = 0; i < m; i++) {
    array[i] = rand() % 50 + 1;
  }
  return array;
}

int main() {
  
  cout << "Bem-Vindo" << endl;
  cout << "Realizaremos 4 casos testes nessa aplicação. Insira a seguir o tamanho de m para cada caso." << endl << endl;

  TabelaHash tabelaDivisao;
  TabelaHash tabelaMultiplicacao;
  TabelaHash tabelaMinhaHash;

  int randomTam;
  int *arr;

  cout << "Primeiramente, insira o tamanho do vetor de inteiros aleatórios: ";
  cin >> randomTam;

  arr = randomArray(randomTam);

  int m;
  for (int i = 0; i < 4; i++) {
    cout << "---- TESTE " << i + 1 << " ----" << endl;
    cout << "M = ";
    cin >> m;

    tabelaDivisao.create(m, MULTIPLICACAO);
    tabelaMultiplicacao.create(m, DIVISAO);
    tabelaMinhaHash.create(m, MINHAHASH);

    for (int i = 0; i < randomTam; i++) {
      tabelaDivisao.insert(i, arr[i]);
      tabelaMultiplicacao.insert(i, arr[i]);
      tabelaMinhaHash.insert(i, arr[i]);
    }

    cout << "----- Resultados -----" << endl;
    cout << "Método da divisão: " << endl;
    tabelaDivisao.print();
    cout << "Colisoes: " << tabelaDivisao.getColisoes() << endl << endl;

    cout << "Método da multiplicacao: " << endl;
    tabelaMultiplicacao.print();
    cout << "Colisoes: " << tabelaMultiplicacao.getColisoes() << endl << endl;

    cout << "Método da MinhaHash: " << endl;
    tabelaMinhaHash.print();
    cout << "Colisoes: " << tabelaMinhaHash.getColisoes() << endl << endl;

  }

  tabelaDivisao.destroy();
  tabelaMultiplicacao.destroy();
  tabelaMinhaHash.destroy();





  
  // TabelaHash table;
  // table.create(12, 10);
  // table.print();
  // table.insert(10, 200);
  // table.print();
  // cout << "Colisoes: " << table.getColisoes() << endl;
  // NoDuplo* p = table.lookup(10, 200);
  // if (p != NULL) {
  //   cout << "Encontrado: " << p->getInfo() << endl;
  // } else {
  //   cout << "Resultado não encontrado" << endl;
  // }
  // table.insert(10, 300);
  // table.print();
  // cout << "Colisoes: " << table.getColisoes() << endl;
  // table.insert(10, 400);
  // table.print();
  // cout << "Colisoes: " << table.getColisoes() << endl;
  // table.insert(10, 300);
  // table.print();
  // cout << "Colisoes: " << table.getColisoes() << endl;
  // table.insert(10, 4000);
  // table.insert(9, 5);
  // table.print();
  // cout << "Colisoes: " << table.getColisoes() << endl;

  // cout << "hashDivisão: " << table.hashDivisao(143) << endl;
  // cout << "hashMultiplicacao: " << table.hashMultiplicacao(144) << endl;


  // --------- TESTE LISTA ---------
  // ListaDupla lista;
  // lista.insereInicio(0);
  // lista.insereInicio(1);
  // lista.insereInicio(2);
  // lista.insereInicio(3);
  // lista.insereInicio(4);
  // lista.insereInicio(5);
  // lista.insereFinal(0);
  // lista.insereFinal(1);
  // lista.insereFinal(2);
  // lista.insereFinal(3);
  // lista.insereFinal(4);
  // lista.insereFinal(5);
  // lista.insereFinal(6);

  // cout << "Quantidade: " << lista.getCount() << endl;
  // lista.print();

  // cout << lista.getFirst() << endl;
  // cout << lista.getLast() << endl;

  // lista.removeFinal();
  // lista.print();

  // cout << lista.getFirst() << endl;
  // cout << lista.getLast() << endl;

  // lista.removeFinal();
  // lista.print();

  // cout << lista.getFirst() << endl;
  // cout << lista.getLast() << endl;

  // lista.insereInicio(-1);
  // lista.print();
  // cout << lista.getFirst() << endl;
  // cout << lista.getLast() << endl;

  return 0;
}