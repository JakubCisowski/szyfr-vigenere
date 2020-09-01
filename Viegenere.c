#include "funkcje.h"

// INFO
// Jesli ktos wczytuje kilka razy ten sam przelacznik, program bierze pod uwage ostatni wczytany
// Jesli ktos wczytuje przelacznik ktory nie istnieje, program go ignoruje
// Program dziala zgodnie z oryginalnym szyfrem Viegnere'a tzn w kluczu mozliwe jedynie litery
// Znaki inne niz litery pozostaja bez zmian po szyfrowaniu, ale przesuwaja klucz

int main(int ileArgumentow, char* argumenty[])
{
	// Parametry programu
	char* kluczSzyfrujacy = malloc(100 * sizeof(char));
	char* plikWejsciowy = malloc(100 * sizeof(char));
	char* plikWyjsciowy = malloc(100 * sizeof(char));

	bool szyfrowanie = false, deszyfrowanie = false;

	printf("PROGRAM URUCHOMIONY --------\n");

	// Wczytywanie przelacznikow podanych przez liste polecen
	if (wczytajPrzelaczniki(ileArgumentow, argumenty, &kluczSzyfrujacy, &plikWejsciowy, &plikWyjsciowy, &szyfrowanie, &deszyfrowanie))
	{
		// Wczytanie danych wejsciowych do bufora
		Bufor* buforTekstu = wczytajDane(plikWejsciowy);
		
		// Operacja na danych wejsciowych
		Viegenere(buforTekstu, kluczSzyfrujacy, szyfrowanie, deszyfrowanie);

		// Zapis z bufora do pliku wyjsciowego
		zapiszDane(buforTekstu, plikWyjsciowy);

		// Zwolnienie pamieci bufora oraz usuniecie struktury 
		usunListe(&buforTekstu);

		printf("Program zostal wykonany pomyslnie, zamykam program.\n");
	}
	else
	{
		printf("Nie udalo sie poprawnie wczytac przelacznikow, zamykam program.\n");
	}

	return 0;
}