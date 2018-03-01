#ifndef DRZEWO_HPP
#define DRZEWO_HPP

struct Wezel{
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
};

class Drzewo{
private:
    Wezel *lewy;
    Wezel *prawy; 
    int stworzWezel(int);				  // aktualna liczba elementow na liscie
public:
    Drzewo();
    ~Drzewo();
    void dodajWezel(int);
    void wyswietlRosnoco();
    bool Usun();
};

#endif
