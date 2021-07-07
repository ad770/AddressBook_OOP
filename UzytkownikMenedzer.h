#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "MetodyPomocnicze.h"

using namespace std;

class UzytkownikMenedzer {
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    int pobierzIdNowegoUzytkownika();

public:
    UzytkownikMenedzer(string nazwaPlkuZUzytkownikami) : plikZUzytkownikami(nazwaPlkuZUzytkownikami) {
        idZalogowanegoUzytkownika = 0;
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int pobierzIdZalogowanegoUzytkownika();
    int wylogowanieUzytkownika();
    bool czyUzytkownikJestZalogowany();
};

#endif // UZYTKOWNIKMENEDZER_H
