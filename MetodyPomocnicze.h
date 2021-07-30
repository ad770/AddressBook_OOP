#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>

using namespace std;

class MetodyPomocnicze {
public:
    static char wczytajZnak();
    static int konwersjaStringNaInt(string liczba);
    static string konwerjsaIntNaString(int liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string wczytajLinie();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();
    static void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    static void usunPlik(string nazwaPlikuZRozszerzeniem);


};

#endif // METODYPOMOCNICZE_H
