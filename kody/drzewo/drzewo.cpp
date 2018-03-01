/*
 * drzewo_bin.cpp
 * 
 * Copyright 2018  <>
 * 
 */

#include <iostream>

using namespace std;

Drzewo:Drzewo(){
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
    *korzen = NULL;
}

void Drzewo::stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel;
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;
    nowyWezel->prawy = NULL;
    
    return nowyWezel;
}

void Drzewo::dodajWezel(Wezel *wezel, int wartosc) {
    if (korzen == NULL) { // drzewo jest puste!
        korzen = stworzWezel(wartosc); // utworzenie 1. elementu
    } else {
        if (wartosc < wezel->wartosc) { // wstawiamy wartość mniejszą
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc);  // rekurencyjne wywołanie dodawanie do lewego poddrzewa
            } else {  // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc);  // tworzymy nowy wezel
            }
        } else { // wstawiamy wartość większą
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc);  // rekurencyjne wywołanie dodawanie do lewego poddrzewa
            } else {  // prawy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc);  // tworzymy nowy wezel
            }
        }
    }
}

// funkcja reukrancyjnie przegądająca drzewo
void Drzewo::wyswietlRosnoco(Wezel *wezel) {
    if (wezel != NULL) { // jeżeli węzeł nie jest pusty
        // reukrencyjnie wyświetl lewe poddrzewo
        wyswietlRosnoco(wezel->lewy);
        // wypisz wartość aktualnego węzła
        cout << wezel->wartosc << ", ";
        // rekurencyjnie wyświetl prawe poddrzewo
        wyswietlRosnoco(wezel->prawy);
    }
}
