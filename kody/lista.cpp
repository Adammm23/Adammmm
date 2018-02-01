/*
 * lista.cpp
 * 
 * 
 */


#include <iostream>
#include "lista.hpp"

Lista::Lista(){
    head = NULL;
    tail = NULL;
}

Lista::~Lista(){
    while(Usun()) {;}; // usunięcie wszystkich elementów listy
}

void Lista::Dodaj(int wartosc) {
    ELEMENT *el = new ELEMENT;
    el->wartosc = wartosc;
    el->nast = NULL;
    if (head == NULL){  // dodanie pierwszego elementu listy
        head = el;
        tail = el;
    } else {
        tail->nast = el;    //ustawienie wskaźnika nast dotychczasowego
        // ostatniego elementu na adres nowego ostatniego elementu
        tail = el;  // aktualizujemy wskaźnik ogon, aby wskazywał na nowy dodany element
    }
}

void Lista::Wyswietl() {
    ELEMENT *el = head;
    while (el != NULL){
        std::cout << el->wartosc << " ";
        el = el->nast;
    }
    std::cout << std::endl;
}

bool Lista::Usun(){
    if (head != NULL) {
        if(head == tail) {  // usunięcie ostatniego elementu
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            ELEMENT *el = head;
            while(el->nast != tail) { // szukam przedostaniego elementu
                el = el->nast; // zapis adresu przedostatniego elementu
            }
            delete el->nast;
            el->nast = NULL;
            tail = el;
        }
        return true;
    }
    return false;
}
