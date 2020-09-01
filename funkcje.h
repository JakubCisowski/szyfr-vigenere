#include "struktury.h"

// Funkcja wczytujaca przelaczniki podane przez liste polecen
bool wczytajPrzelaczniki(int ileArgumentow, char* argumenty[], char** kluczSzyfrujacy, char** plikWejsciowy, char** plikWyjsciowy, bool* szyfrowanie, bool* deszyfrowanie);

// Funkcja sprawdzajaca czy podany klucz jest poprawny
int sprawdzKlucz(char* klucz);

// Funckja wczytujaca dane z pliku wejsciowego do bufora
Bufor* wczytajDane(char* plikWejsciowy);

// Funkcja zapisujaca dane z bufora do pliku wyjsciowego
void zapiszDane(Bufor* glowa, char* plikWyjsciowy);

// Funkcja dodajaca element na koniec bufora
Bufor* wstawNaKoniec(Bufor* glowa, char* wartosc);

// Funkcja tworz¹ca nowy element bufora
Bufor* nowyElement(char* wartosc);




// Do usuniecia
void print(Bufor* head);