class NoDuplo {
  public:
    NoDuplo();
    ~NoDuplo();

    void setAnt(NoDuplo *p);
    void setProx(NoDuplo *p);
    void setInfo(int val);

    NoDuplo* getAnt();
    NoDuplo* getProx();
    int getInfo();

  private:
    NoDuplo *ant;
    int info;
    NoDuplo *prox;
};