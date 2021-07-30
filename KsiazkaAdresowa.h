#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "Menu.h"
#include "PlikZAdresatami.h"

using namespace std;

class KsiazkaAdresowa {
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer *adresatMenedzer;
    Menu menu;
    const string NAZWA_PLIKU_Z_ADRESATAMI;
    char wybor;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adresatMenedzer = NULL;

        while (true) {
            if (!uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
                wybor = menu.wybierzOpcjeZMenuGlownego();
                switch (wybor) {
                case '1':
                    rejestracjaUzytkownika();
                    break;
                case '2':
                    logowanieUzytkownika();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                    system("pause");
                    break;
                }
            } else {
                wybor = menu.wybierzOpcjeZMenuUzytkownika();

                switch (wybor) {
                case '1':
                    dodajAdresata();
                    break;
                case '2':
                    wyszukajAdresatowPoImieniu();
                    break;
                case '3':
                    wyszukajAdresatowPoNazwisku();
                    break;
                case '4':
                    wyswietlWszystkichAdresatow();
                    break;
                case '5':
                    usunAdresata();
                    break;
                case '6':
                    edytujAdresata();
                    break;
                case '7':
                    zmianaHaslaZalogowanegoUzytkownika();
                    break;
                case '8':
                    wylogowanieUzytkownika();
                    break;
                }
            }
        }
    };

    ~KsiazkaAdresowa() {
        delete adresatMenedzer;
        adresatMenedzer = NULL;
    }

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void edytujAdresata();
    void usunAdresata();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wyswietlWszystkichAdresatow();
    void wypiszWszystkichUzytkownikow();
};

#endif // KSIAZKAADRESOWA_H
