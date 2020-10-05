#include <iostream>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla() {
  primeiro = NULL;
  ultimo = NULL;
  n = 0;
}

NoDuplo* ListaDupla::insereInicio(int val) {
  NoDuplo *p = new NoDuplo;
  p->setInfo(val);
  p->setProx(primeiro);
  p->setAnt(NULL);

  if (n == 0) {
    ultimo = p;
  } else {
    primeiro->setAnt(p);
  }

  primeiro = p;
  n += 1;

  return p;
}

void ListaDupla::removeInicio() {
  NoDuplo *p;
  if (primeiro != NULL) {
    p = primeiro;
    primeiro = p->getProx();
    delete p;
    n -= 1;
    
    if (n == 0) {
      ultimo = p;
    } else {
      primeiro->setAnt(NULL);
    }
  } else {
    exit(0);
  }
}

NoDuplo* ListaDupla::insereFinal(int val) {
  NoDuplo *p = new NoDuplo;
  p->setInfo(val);
  p->setProx(NULL);

  if (n == 0) {
    primeiro = p;
  } else {
    p->setAnt(ultimo);
  }

  if (ultimo != NULL) {
    ultimo->setProx(p);
  }

  ultimo = p;
  n += 1;

  return p;
}

void ListaDupla::removeFinal() {
  NoDuplo *p;
  if (ultimo != NULL) {
    p = ultimo;
    ultimo = p->getAnt();
    ultimo->setProx(NULL);
    delete p;
  } else {
    exit(0);
  }
}

int ListaDupla::getFirst() {
  if (primeiro != NULL) {
    return primeiro->getInfo();
  }
  return -1;
}

int ListaDupla::getLast() {
  if (ultimo != NULL) {
    return ultimo->getInfo();
  }
  return -1;
}

int ListaDupla::getCount() {
  return n;
}

void ListaDupla::print() {
  NoDuplo* p = primeiro;
  while(p != NULL) {
      cout << p->getInfo() << " ";
      p = p->getProx();
  }
  cout << endl;
}

NoDuplo* ListaDupla::busca(int val) {
  NoDuplo *p = primeiro;
  while (p != NULL) {
    if (p->getInfo() == val) {
      return p;
    }
    p = p->getProx();
  }
  return NULL;
}

void ListaDupla::destroy() {
  NoDuplo *p = primeiro;
  while (p != NULL) {
    NoDuplo *t = p->getProx();
    delete p;

    p = t;
  }
}