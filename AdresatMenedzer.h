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

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlDaneAdresata(Adresat adresat);
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string nazwaPlkuZAdresatami) : plikZAdresatami(nazwaPlkuZAdresatami) {};

    int dodajAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    void wyswietlWszystkichAdresatow();
};

#endif // ADRESATMENEDZER_H
