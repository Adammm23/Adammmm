/*
 * szyfr_cezara. cpp
 */


#include <iostream>

using namespace std;

vid szyfruj(char tekst[], int klucz){
    klucz = klucz % 26;
    int i = 0;
    while (tekst[i] != '\0') {
        if ((int)tekst[i] + klucz > 122)
            tekst[i] = (char)(int)tekst[i] + klucz - 26
        else
            ;
        i++;
    }
}

int main(int argc, char **argv)
{
    char tekst[100];
    int klucz = 3;
    cout << "Podaj tekst: " << endl;
    cin >> tekst;
    cout << "Podaj klucz; ";
    cin >> klucz;
    szyfruj(tekst, klucz);
    coun << tekst;

	return 0;
}

