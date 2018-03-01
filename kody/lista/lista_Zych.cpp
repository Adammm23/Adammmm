/*
 * lista.cpp
 * 
 * Copyright 2018  <>
 * 
 */


#include <iostream>
#include "lista.hpp"

using namespace std;

Lista::Lista() {
    head = NULL;
    tail = NULL;
    i = 0;
}

Lista::~Lista() {
    while(Usun())   {;}; //usuniecie 
}

void Lista::Dodaj(int a) {
    ELEMENT *el = new ELEMENT;
    el -> wartosc = a;
    el -> wskaznik = NULL;
    
    if (head == NULL){ // dodanie piierwszego elementu listy
        head = el;
        tail = el;
        i = 1;
    } else {
        tail -> wskaznik = el;      // ustawienie wksaznika nast dotychczasowego
        // ostatniego elementu na adres nowego ostatniego elementu
        tail = el; // aktualizujemy wslazmol ogon aby wkazywal na nowy dodany element
        i++;
    }
}

void Lista::Wyswietl() {
    ELEMENT *el = head;
    
    while (el != NULL) {
        cout << el -> wartosc << " ";
        el = el -> wskaznik;
    }
    
    cout << endl;
}

bool Lista::Usun(){
    if(head != NULL) {              // lista zawiera elementy
        if (tail == head) {
            delete head;            // usuwamy zmienna wskazywana przez head
            head = NULL;
            tail = NULL;
        } else {
            ELEMENT *el = head;
            while(el -> wskaznik != tail) { //szukam przedostatniego elementu
                el = el -> wskaznik; //zapis adresu przedostatniego
            }
            delete el -> wskaznik;
            el -> wskaznik = NULL;
            tail = el;              // aktualizacja wskaznika ostatniego elementu
            i--;
        }
        return true;
    }
    return false;
}

void Lista::Wstaw(int pozycja, int wartosc){
	if (pozycja < 0)	pozycja *= (-1);	// wartosc bezwzgledna
    if(pozycja != 0){
		if(pozycja > i){
			Dodaj(wartosc);				// definicja powiekdzenia listy
		}
		else if (pozycja == 1) {		// zmiana na head
			ELEMENT *el = new ELEMENT;
			el -> wartosc = wartosc;
			el -> wskaznik = head;
			head = el;
			i++;
		} else {
			ELEMENT *el = new ELEMENT;
			el -> wartosc = wartosc;	// przypisanie nowej wartosci
			
			ELEMENT *p = head;		// wskaznik pomocniczy

			for (int j = 1; j != pozycja - 1; j++)
				p = p -> wskaznik;	// dotarcie do poprzedniej pozycji

			el -> wskaznik = p -> wskaznik;
			p -> wskaznik = el;
			
			i++;
		}
	}
}
