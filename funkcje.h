#include "struktury.h"

// Funkcja wczytujaca przelaczniki podane przez liste polecen
bool wczytajPrzelaczniki(int ileArgumentow, char* argumenty[], char** kluczSzyfrujacy, char** plikWejsciowy, char** plikWyjsciowy, bool* szyfrowanie, bool* deszyfrowanie);

// Funkcja sprawdzajaca czy podany klucz jest poprawny
int checkKey(char key[]);