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
    AdresatMenedzer adresatMenedzer;
    Menu menu;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    char wybor;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami),
          adresatMenedzer(nazwaPlikuZAdresatami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        idZalogowanegoUzytkownika=0;
        idOstatniegoAdresata=0;

        while (true) {
            if (idZalogowanegoUzytkownika == 0) {
                wybor = menu.wybierzOpcjeZMenuGlownego();

                switch (wybor) {
                case '1':
                    uzytkownikMenedzer.rejestracjaUzytkownika();
                    break;
                case '2':
                    idZalogowanegoUzytkownika = uzytkownikMenedzer.logowanieUzytkownika();
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
//                if (adresaci.empty() == true)
//                    // Pobieramy idOstatniegoAdresata, po to aby zoptymalizowac program.
//                    // Dzieki temu, kiedy uztykwonik bedzie dodawal nowego adresata
//                    // to nie bedziemy musieli jeszcze raz ustalac idOstatniegoAdresata
//                    idOstatniegoAdresata = wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci, idZalogowanegoUzytkownika);
                adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
                idOstatniegoAdresata=adresatMenedzer.pobierzZPlikuIdOstatniegoAdresata();
                wybor = menu.wybierzOpcjeZMenuUzytkownika();

                switch (wybor) {
                case '1':
                    adresatMenedzer.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                    break;
                case '2':
                    //wyszukajAdresatowPoImieniu(adresaci);
                    break;
                case '3':
                    //wyszukajAdresatowPoNazwisku(adresaci);
                    break;
                case '4':
                    adresatMenedzer.wyswietlWszystkichAdresatow();
                    break;
                case '5':
                    //idUsunietegoAdresata = usunAdresata(adresaci);
                    //idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                    break;
                case '6':
                    //edytujAdresata(adresaci);
                    break;
                case '7':
                    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                    break;
                case '8':
                    idZalogowanegoUzytkownika = 0;
//                    adresaci.clear();
                    break;
                }
            }
        }

//        uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
    };

    void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
};

#endif // KSIAZKAADRESOWA_H
