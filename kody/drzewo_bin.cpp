/*
 * drzewo_bin.cpp
 * 
 * 
 * 
 */

#include <iostream>

using namespace std;

struct Wezel {
    int wartosc;
    Wezel *lewy;
    Wezel *prawy;
} *korzen = NULL; // definicja struktury i utworzenie wskaźnika korzen

Wezel* stworzWezel(int wartosc) {
    Wezel *nowyWezel = new Wezel;
    nowyWezel->wartosc = wartosc;
    nowyWezel->lewy = NULL;    
    nowyWezel->prawy = NULL;
    
    return nowyWezel;    
}

void dodajWezel(Wezel *wezel, int wartosc) {
    if (korzen == NULL) { // drzewo jest puste
        korzen = stworzWezel(wartosc); // utworzenie 1. elementu            
    } else {
        if (wartosc < wezel->wartosc) { // wstawiamy wartość mniejszą
            if(wezel->lewy != NULL) {
                dodajWezel(wezel->lewy, wartosc); // rekurancyjne dodawanie do lewego poddrzewa
            } else { // lewy potomek nie istnieje
                wezel->lewy = stworzWezel(wartosc); // twoerzymy nowy wezel            
            }
        } else { // wstawiamy wartość większą
            if(wezel->prawy != NULL) {
                dodajWezel(wezel->prawy, wartosc); // rekurancyjne dodawanie do lewego poddrzewa
            } else { // prawy potomek nie istnieje
                wezel->prawy = stworzWezel(wartosc); // twoerzymy nowy wezel            
            }
        }
    }
}

int main(int argc, char **argv)
{
	
	return 0;
}

