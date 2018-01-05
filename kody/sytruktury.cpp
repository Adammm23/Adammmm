/*
 * sytruktury.cpp
 */


#include <iostream>
#include <iomanip>
#include <fstream>


using namespace std;

struct osoba {
    char imie[20];
    char nazwisko[20];
    int wiek;    
};

//~struct samochod {
    //~char kolor[20];
    //~int kola;
    //~int drzwi;    
//~};

//~void wyswietlDane(osoba o) {
        //~cout << setw(20) << left << "Imię: " << setfill('_') << right << o.imie << endl;
        //~cout << setw(20) << left << "Nazwisko: " << setfill('_') << right << o.nazwisko << endl;
        //~cout << setw(20) << left << "Wiek: " << setfill('_') << right << o.wiek << endl;
//~}

//~void wyswietlDane(samochod s) {
        //~cout << setw(20) << left << "Kolor: " << setfill('_') << right << s.kolor << endl;
        //~cout << setw(20) << left << "Ilośc kół: " << setfill('_') << right << s.kola << endl;
        //~cout << setw(20) << left << "Ilość drzwi: " << setfill('_') << right << s.drzwi << endl;
//~}

void getOsoby(osoba t[], int ile) {
    for(int i=0; i < ile; i++) {
        cout << "Podaj imię: ";
        cin >> t[i].imie;
        cout << "Podaj nazwisko: ";
        cin >> t[i].nazwisko;
        cout << "Podaj wiek: ";
        cin >> t[i].wiek;
    }
}

void drukujOsoby(osoba t[], int ile){
    for(int i=0; i < ile; i++) {
       	cout << setw(20) << left << "Imię: " << setfill('.') << right << t[i].imie << endl;
        cout << setw(20) << left << "Nazwisko: " << setfill('.') << right << t[i].nazwisko << endl;
        cout << setw(20) << left << "Wiek: " << setfill('.') << right << t[i].wiek << endl;
        
    }
}

void zapiszDane(osoba t[], int ile){
    ofstream plik("osoby.txt", ios::app);
    if (!plik.is_open()) {
        cout << "Błąd otwarcia pliku!";
    } else {
        for(int i=0; i < ile; i++){
            cout << t[i].imie << "," << t[i].nazwisko << "," << t[i].wiek << endl;
            plik << t[i].imie << "," << t[i].nazwisko << "," << t[i].wiek << endl;            
        }
    }
}

int czytajDane(osoba t[]){
    ifstream plik("osoby.txt");
    string linia;
    int i = 0;    
    
    if (plik.is_open()) {
        while(getline(plik, linia)) {
            cout << linia << endl;
            i++; // liczymy przeczytane rekordy
        }
    } else {
        cout << "Błąd otwarcia pliku!";
    }
    return i;
}

int main(int argc, char **argv)
{
	//~osoba uczen1;
    //~cout << "Podaj imię: ";
    //~cin >> uczen1.imie;
    //~cout << "Podaj nazwisko: ";
    //~cin >> uczen1.nazwisko;
    //~cout << "Podaj wiek: ";
    //~cin >> uczen1.wiek;
    //~wyswietlDane(uczen1);
    
    //~samochod auto1;
    //~cout << "Podaj kolor: ";
    //~cin >> auto1.kolor;
    //~cout << "Podaj ilość kół: ";
    //~cin >> auto1.kola;
    //~cout << "Podaj ilość drzwi: ";
    //~cin >> auto1.drzwi;
    //~wyswietlDane(auto1); 
    
    int ile;
    cout << "Ile osób? "; cin >> ile;
    osoba tb[ile];
    //~getOsoby(tb, ile);
    //~zapiszDane(tb, ile);
    cout << czytajDane(tb) << endl;
    
	return 0;
}

