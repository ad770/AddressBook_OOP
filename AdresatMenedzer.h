#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
#include "Menu.h"

using namespace std;

class AdresatMenedzer {
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Menu menu;
    string nazwaPlikuZUzytkownikami = "Uzytkownicy.txt";
    string nazwaPlikuZAdresatami = "Adresaci.txt";
    string nazwaTymczasowegoPlikuZAdresatami = "Adresaci_tymczasowo.txt";


    Adresat podajDaneNowegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    void usunWybranegoAdresataZPliku(int idUsuwanegoAdresata);
    int podajIdWybranegoAdresata();
    void edytujAdresataWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    void zaktualizujDaneWybranegoAdresata(Adresat adresat);


public:
    AdresatMenedzer(string nazwaPlkuZAdresatami, int idZalogowanegoUzytkownika)
    : plikZAdresatami(nazwaPlkuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };

    void dodajAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edytujAdresata();
};

#endif // ADRESATMENEDZER_H
