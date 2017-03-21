/*
 * szyfr_cezara. cpp
 */


#include <iostream>

using namespace std;

void szyfruj(char tekst[], int klucz){
    klucz = klucz % 26;
    int i = 0;
    while (tekst[i] != '\0') {
		if (tekst[i] == ' ')
			continue;

		if ((int)tekst[i] >= 65 && (int)tekst[i] <= 90)
			tekst[i] = tekst[i] + 32;

		if ((int)tekst[i] + klucz > 122)
			tekst[i] = char((int)tekst[i] - 26 + klucz);
		else
			tekst[i] = char((int)tekst[i] + klucz);
		i++;
	}
	cout << tekst << endl;
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
    cout << tekst;

	return 0;
}

