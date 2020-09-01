#include "struktury.h"

// Funkcja wczytujaca przelaczniki podane przez liste polecen
bool wczytajPrzelaczniki(int ileArgumentow, char* argumenty[], char** kluczSzyfrujacy, char** plikWejsciowy, char** plikWyjsciowy, bool* szyfrowanie, bool* deszyfrowanie);

// Funkcja sprawdzajaca czy podany klucz jest poprawny
int sprawdzKlucz(char* klucz);

// Funckja wczytujaca dane z pliku wejsciowego do bufora
Bufor* wczytajDane(char* plikWejsciowy);

// Funkcja zapisujaca dane z bufora do pliku wyjsciowego
void zapiszDane(Bufor* glowa, char* plikWyjsciowy);

// Funkcja nadzorujaca odpowiednia operacje (szyfr/deszyfr) na danych w buforze
void Viegenere(Bufor* glowa, char* klucz, bool szyfrowanie, bool deszyfrowanie);

// Funkcja pomocnicza konwertujaca klucz w postaci liter na klucz z liczbami
void konwertujKlucz(int* kluczLiczbowy, char* klucz);

// Funkcja szyfrujaca/deszyfrujaca 
char* szyfruj(char* napis, int* indeks, int* klucz, bool szyfrowanie, bool deszyfrowanie);

// -------

// Funkcja dodajaca element na koniec bufora
Bufor* wstawNaKoniec(Bufor* glowa, char* wartosc);

// Funkcja tworz¹ca nowy element bufora
Bufor* nowyElement(char* wartosc);

// Funkcja usuwajaca bufor z pamieci
void usunListe(Bufor** glowa);